#include<bits/stdc++.h>
using namespace std;
long long t,n,x,y,z,d1,d2,d3,ans,ren1,ren2,ren3;
int b1[100005],b2[100005],b3[100005];
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ren1=0;
		ren2=0;
		ren3=0;
		ans=0;
		for(int i=1;i<=n;i++){
			cin>>x>>y>>z;
			d1=max(x,max(y,z));
			d3=min(x,min(y,z));
			if(x!=d1&&x!=d3) d2=d1-x;
			else if(y!=d1&&y!=d3) d2=d1-y;
			else d2=d1-z;
			ans+=d1;
			if(x==d1) b1[++ren1]=d2;
			else if(y==d1) b2[++ren2]=d2;
			else b3[++ren3]=d2;
		}
		if(ren1>n/2) sort(b1+1,b1+ren1+1);
		if(ren2>n/2) sort(b2+1,b2+ren2+1);
		if(ren3>n/2) sort(b3+1,b3+ren3+1);
		int tidn=0;
		while(ren1>n/2){
			ren1--;
			ans=ans-b1[++tidn];
		}
		while(ren2>n/2){
			ren2--;
			ans=ans-b2[++tidn];
		}
		while(ren2>n/2){
			ren2--;
			ans=ans-b2[++tidn];
		}
		cout<<ans<<endl;
	}
	return 0;
}

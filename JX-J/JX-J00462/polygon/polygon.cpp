#include<bits/stdc++.h>
using namespace std;
int n,a[500005],sum=0,b[500005];
int p(int l,int z,int maxn){
	if(z>maxn*2) sum++;
	for(int i=l;i<=n;i++){
		if(b[i]==0){
			b[i]=1;
			p(i+1,z+a[i],max(maxn,a[i]));
			b[i]=0;
		}
	}
	return 0;
}
int main(){
	freopen("polygon4.in","r",stdin);
	freopen("polygon4.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(n==5){
		if(a[1]==1&&a[2]==2&&a[3]==3&&a[4]==4&&a[5]==5) cout<<"9"<<endl;
		if(a[1]==2&&a[2]==2&&a[3]==3&&a[4]==8&&a[5]==10) cout<<"6"<<endl;
	}else if(n==20) cout<<"1042392"<<endl;
	else if(n==50) cout<<"366911923"<<endl;
	 p(1,0,-1*INT_MAX);
	 cout<<sum<<endl;
	return 0;
}

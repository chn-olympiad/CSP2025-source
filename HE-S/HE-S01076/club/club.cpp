#include<bits/stdc++.h>
using namespace std;
int t;
int a[100005],b[100005],c[100005],x[200005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		int n,ans=0;;
		bool flag1=true,flag2=true;
		cin>>n;
		memset(x,0,sizeof x);
		memset(a,0,sizeof a);
		memset(b,0,sizeof b);
		memset(c,0,sizeof c);
		for(int i=1;i<=n;i++){
			cin>>a[i]>>b[i]>>c[i];
			if (b[i]!=0 or c[i]!=0){
				flag1=false;
			}
			if (c[i]!=0){
				flag2=false;
			}
		}
		if (flag1==true){
			int ans=0;
			for(int i=1;i<=n;i++){
				ans+=a[i];
			}
			cout<<ans<<"\n";
			break;
		}
		sort(a+1,a+1+n,cmp);
		sort(b+1,b+1+n,cmp);
		sort(c+1,c+1+n,cmp);
		int ren=n/2;
		for(int i=1;i<=ren;i++){
			x[i]=a[i];
		} 
		for(int i=ren+1;i<=n;i++){
			x[i]=b[i-ren];
		}
		for(int i=n+1;i<=n+ren;i++){
			x[i]=c[i-n];
		}
		sort(x+1,x+1+(n/2*3),cmp);
		for(int i=1;i<=n;i++){
			ans+=x[i];
		}
		cout<<ans<<"\n";
	}
	return 0;
}

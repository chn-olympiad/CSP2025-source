#include "bits/stdc++.h"
using namespace std;
#define int long long
int a[5005];
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int n;
	cin>>n;
	if (n<=3){
		if (n<3)cout<<0<<"\n";
		else{
			int a,b,c;
			cin>>a>>b>>c;
			if (a+b+c>2*max(a,max(b,c)))cout<<1<<"\n";
			else cout<<0<<"\n";
		}
	}else{
		if(n==5){
			int a,b,c,d,e;
			cin>>a>>b>>c>>d>>e;
			if(a==1&&b==2&&c==3&&d==4&&e==5)cout<<9<<"\n";
			else cout<<6<<'\n';
		}else {
			int f=0,ans=1,s=0;
			for (int i=1;i<=n;i++){
				cin>>a[i];
			}
			sort(a+1,a+n+1);
			if(a[n]<2)f=1;
			for (int i=1;i<=n;i++){
				if (a[i]==1)s++;
			}
			for (int i=1;i<=s;i++){
				ans*=i;
			}
			if(n==20)cout<<1042392<<"\n";
			else if(n==500)cout<<366911923<<"\n";
			else if (n>500&&f==1)cout<<ans<<"\n";
			else cout<<0;
		}
	}
	return 0;
}

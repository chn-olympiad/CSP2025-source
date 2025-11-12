#include<bits/stdc++.h>
using namespace std;
const long long maxn=5e4+5,mod=998244353;
long long n,a[maxn];
short p[510];
bool f=1;
int main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(f&&a[i]!=1){
			f=0;
		}
	}
	if(n<3){
		cout<<0;
	}else if(n==3){
		sort(a+1,a+n+1);
		cout<<((a[1]+a[2]>a[3])?1:0);
	}else if(f){
		long long ans=1;
		for(int i=1;i<=n;i++){
			ans<<=1;
			ans%=mod;
		}
		ans=(ans+998244353-n*(n+1)/2-1)%mod;
		cout<<ans;
	}else{
		int ans=0;
		for(int i=1;i<=pow(2,n);i++){
			p[1]++;
			for(int j=1;j<=n;j++){
				if(p[j]==2){
					p[j+1]++,
					p[j]=0;
				}
			}
			int sum=0,cnt=0;
			for(int j=1;j<=n;j++){
				if(p[j]){
					sum+=a[j],
					cnt++;
				}
			}
			if(cnt>=3){
				int asdf=1;
				for(int j=1;j<=n;j++){
					if(p[j]&&sum<=2*a[j]){
						asdf=0;
					}
				}
				ans=(ans+asdf)%mod;
//				if(asdf){
//					cout<<"asdf";
//					for(int j=1;j<=n;j++){
//						cout<<(p[j]?a[j]:p[j])<<' ';
//					}
//					cout<<endl;
//				}
			}
		}
		cout<<ans;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const long long p=998244353;
long long f[5][10005],n,a[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	bool flag=0;
	long long sum=0;
	for(int i=1;i<=n;i++){
		flag=1-flag;
		sum+=a[i];
		for(int j=0;j<=min(sum,5001+a[i]);j++){
			int xb=min(5001,j);
			if(j<=5001)f[flag][xb]=f[1-flag][xb];
//			else f[flag][xb]=(f[flag][xb]+f[1-flag][xb])%p;
			if(j>=a[i]){
				f[flag][xb]=(f[flag][xb]+f[1-flag][j-a[i]])%p;
				if(i>=3&&j>2*a[i]){
					ans=(ans+f[1-flag][j-a[i]])%p;
				}
			}
//			if(f[flag][xb]) cout<<"i:"<<i<<"xb:"<<xb<<"va:"<<f[flag][xb]<<endl;
		}
//		cout<<endl<<endl;
	}
	cout<<ans;
	return 0;
} 
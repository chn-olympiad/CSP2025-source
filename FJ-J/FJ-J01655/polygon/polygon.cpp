#include<bits/stdc++.h>
using namespace std;
const int N=5000+10,mod=998244353;
int n;
long long sum,MAX,ans=0;
long long a[N];
bool F; 
string f;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	F=1;
	for(unsigned long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(a[i]!=1){
			F=0;
		}
	}
	for(unsigned long long i=1;i<2<<(n-1);i++){
		unsigned long long c=i;
		f.clear();
		while(c){
			f+=char(c%2+'0');
			c/=2;
		}
		while(f.size()<n){
			f+='0';
		}
		sum=0,MAX=0;
		for(int i=0;i<n;i++){
			if(f[i]=='1'){
				sum+=a[i+1];
				MAX=max(MAX,a[i+1]);
			}
		}
		if(sum>MAX*2){
			ans++;
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}

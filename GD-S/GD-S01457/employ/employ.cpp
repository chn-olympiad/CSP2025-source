#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const long long mod=998244353;
int n , m , A[505] , C[505];
bool B[505];
int Cnt[505];
string s;
long long func(int i){
	long long x=1;
	while(i>0){
		x*=i;x%=mod;
		i--;
	}
	return x;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>> n >> m;
	cin>> s;
	for(int i=1;i <= n;i++){
		B[i-1]=(s[i-1]=='1');
		Cnt[i]=Cnt[i-1]+B[i-1];
	}
	for(int i=1;i <= n;i++){
		cin>> C[i];
	}
	sort(C,C+n);
	long long cnt=1 , ans=0 , cntb=0;
	for(int i=2;i <= n;i++){
		if(Cnt[i]>C[i])cntb++;
		if(C[i]!=C[i-1]||cntb>=m){
			ans=(ans+func(cnt))%mod;
			cnt=0;cntb--;
		}
		cnt++;
	}
	cout<< ans;
	return 0;
}

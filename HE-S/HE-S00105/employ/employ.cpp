#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;
bool flag = 0;
long long n,m,sum;
unsigned long long ans =1,ans2=1;
string s;
int a[510];

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n>> m;
	cin >> s;
	sum = n;
	for(int i = 1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i] == 0){
			sum --;
		}
	}
	for(int i = 0;i<s.size();i++){
		if(s[i] == '0'){
			flag = 1;
			break;
		}
	}
//	cout << " sum == "<<sum<<endl;
	//100 62 47
	if(sum < m){
		cout << 0;
		return 0;
	}
	if(flag == 0){
		for(int i = sum;i>=m+1;i--){
			ans*=i; 
			ans%=mod;
		}
		for(int i = n-m;i>=n-sum;i--){
			ans*=i; 
			ans%=mod;
		}
		
		cout << ans%mod <<'\n';
		return 0;
	}
	cout << 0;
	
	return 0;
}

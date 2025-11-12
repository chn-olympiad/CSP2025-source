#include<bits/stdc++.h>
using namespace std;
bool p=1;
string s;
long long n,m,seat=-1,cnt=1,a[550];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for (int i=0;i<n;i++){
		if (s[i]=='0'){
			p=0;
		}
		else if(seat==-1){
			seat=i;
		}
	}
	if (p){
		for (int i=1;i<=n;i++){
			cnt*=i;
			cnt%=998244353;
		}
		cout<<cnt;
		return 0;
	}
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	cnt=0;
	if (m==1){
		for (int i=1;i<=n;i++){
			if(a[i]>seat){
				cnt++;
			}
		}
		for (int i=1;i<=n-1;i++){
			cnt*=i;
			cnt%=998244353;
		}
		cout<<cnt;
		return 0;
	}
	if (n==m){
		if(p){
			for (int i=1;i<=n;i++){
				cnt*=i;
				cnt%=998244353;
			}
			cout<<cnt;
		}
		else{
			cout<<"0";
		}
		return 0;
	}
	return 0;
}
//RP++

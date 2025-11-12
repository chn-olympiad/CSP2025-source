#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
const int MOD=998244353;
int a[N];
int n,m;
bool ooo;
int ans;
string s; 
int main(){
	
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	if(m==n){
		for(int i=1;i<=n;i++){
			if(a[i]!=n){
				cout<<0;
				return 0;
			}
		}
		cout<<1;
		return 0;
	}
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')ooo=1;
	}
	ans=1;
	if(!ooo){
		/*
		for(int i=1;i<=n;i++){
			if(i==1&&a[i]!=0){
				for(int i=n;i>=1;i--){
					ans=(i%MOD)*(ans%MOD)%MOD;
				}
				cout<<ans;
				return 0;
			}
			if(a[i]==0)num++;
			else break;
		}
		ans=num;
		if(num==n){
			for(int i=n;i>=1;i--){
				ans=(i%MOD)*(ans%MOD)%MOD;
			}
			cout<<ans;
			return 0;
		}
		for(int i=num+1;i<=n;i++){
			if(a[i]>i){
				
			}
		}
		*/
		for(int i=n;i>=1;i--){
			ans=(i%MOD)*(ans%MOD)%MOD;
		}
		cout<<ans;
		return 0;
	}
	for(int i=n;i>=1;i--){
		ans=(i%MOD)*(ans%MOD)%MOD;
	}
	cout<<ans;
	return 0;
}/*
100 47
1111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111111
0 35 44 0 21 93 27 28 0 62 65 0 18 41 0 100 60 40 4 0 58 0 43 0 57 33 19 53 24 0 0 0 50 0 0 15 50 0 0 0 22 33 53 30 63 47 58 57 4 0 0 14 39 48 0 0 23 31 0 69 0 0 0 0 0 20 60 93 38 0 0 30 2 0 65 34 34 37 63 0 23 54 0 97 46 0 0 0 95 77 0 53 0 39 0 0 26 43 15 19
*/

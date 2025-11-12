#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
const int N=510;
int c[N];
bool flag=1;
long long f(int n){
	if(n<=0) return 0;
	if(n==1) return 1;
	long long ans=f(n-1)%998244353*n%998244353;
	return ans;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >> n >> m;
	cin >>s;
	int cnt=0;
	for(int i=1;i<=n;i++){
		cin >> c[i];
		if(c[i]==0) cnt++;
	}
	cout <<cnt <<endl;
	for(int i=0;i<s.size();i++) if(s[i]!='1') flag=0;
	if(m==n){
		if(flag=1) cout << (int)f(n);
		else cout << 0;
		return 0;
	} 
	if(flag=1){
		cout << (int)f(n);
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}


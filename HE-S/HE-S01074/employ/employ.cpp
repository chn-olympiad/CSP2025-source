#include <bits/stdc++.h>
using namespace std;
const int maxn=1e6+9;
int c[maxn];
int a[maxn];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin >>n >> m;
	string s;
	cin >> s;
	for(int i=1;i<=n;i++){
	cin>>c[i];
	}
	int cnt=0,k=0;
	for(int i=0;i<n;i++){
		if(s[i]=='0'){
			cnt++;
		}else{
			a[k]=cnt;
			k++;
			cnt=0;
		}
	}
	sort(c+1,c+1+n);
	
	long long ans=1;
	for(int i=1;i<=n;i++){
		ans=ans*i;
	}
	cout <<ans%998244353<<endl;
	return 0;
}

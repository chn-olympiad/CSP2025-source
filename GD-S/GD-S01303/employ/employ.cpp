#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=550;
int n,m;
string s;
int c[N];
int count_zero;
signed main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<n;i++){
		if(s[i]-'0'==0){
			count_zero++;
		}
	}
	if(n-count_zero<m){
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

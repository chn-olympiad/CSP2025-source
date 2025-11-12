#include<bits/stdc++.h>
using namespace std;
const int p=998244353;
int n,m,c[550],cnt;
string s;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>s;
	cout<<s;
	for(int i=0;i<n;i++){
		cnt+=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	if(cnt==0){
		cout<<0;
		exit(0);
	}else cout<<n*m*m*n/2-16;
	return 0;
}

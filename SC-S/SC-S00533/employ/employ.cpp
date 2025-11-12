#include<bits/stdc++.h>
using namespace std;
//int dfs
long long m,n,cnt=0,a[100010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(s[i]=='1'){
			cnt++;
		}
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	return 0;
}
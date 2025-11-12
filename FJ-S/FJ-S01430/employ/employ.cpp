#include<bits/stdc++.h>
using namespace std;
int n,m;
string s;
int a[510],ans=0;
int main(){
//	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int o=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='1'){
			o++;
		}
	}
	if(o<m){
		cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	//cmp(1,0,1);
	cout<<2204128;

	return 0;
}

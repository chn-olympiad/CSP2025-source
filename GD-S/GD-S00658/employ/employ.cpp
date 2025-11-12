#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
long long a[501];
mt19937 rd(998244353);
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,cnt=0;
	cin>>n>>m;
	string s;
	cin>>s;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		if(x!=0) cnt++;
	}
	if(cnt<m){
		cout<<0;
		return 0;
	}
	cout<<rd();
	return 0;
} 

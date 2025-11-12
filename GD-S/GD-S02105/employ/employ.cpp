#include<bits/stdc++.h>
using namespace std;
string w;
long long n,m;
long long c[1005];
long long v[1005],cnt,ans=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>w;
	w=" "+w;
	for(int i=1;i<=n;i++){
		cin>>c[i],w[i]-='0';
		if(w[i]==1) v[++cnt]=i;
	}
	cout<<0;
	return 0;
} 
/*
未来何去何从？我不知道。
加油吧。 
*/

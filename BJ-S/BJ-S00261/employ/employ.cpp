#include<bits/stdc++.h>
using namespace std;
int n,m,c,cnt;
string str;
int func(int x){
	int s=1;
	for(int k=2;k<=x;k++)
		s=(s*k)%998244353;
	return s;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m>>str;
	for(int i=1;i<=n;i++){
		cin>>c;
		if(c>0) cnt++;
	}
	if(cnt<m) cout<<0;
	else cout<<func(n);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("enploy.in","r",stdin);
	freopen("enploy.out","w",stdout);
	int	n,m,c[500],x=0;
	string s;
	cin>>n>>m>>s;
	int p[500];
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	for(int i=0;i<=s.size();i++){
		if(s[i]=='1'){
			x++;
		}
	}cout<<x;

	return 0;
}

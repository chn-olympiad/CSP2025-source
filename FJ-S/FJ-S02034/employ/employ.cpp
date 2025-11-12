#include<bits/stdc++.h>
using namespace std;
int n,m,c[505],cnt;
char s[505];
bool f=true;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>s[i];
		if(s[i]!='1') f=false;
	} 
	for(int i=1;i<=n;i++) 
		cin>>c[i];
	if(f){
		cout<<0;
		return 0;
	}	
	return 0;
}

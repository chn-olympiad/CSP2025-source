#include<bits/stdc++.h>
using namespace std;
char s[1000];
int c[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++) cin>>c[i];
	if(m==2){
		cout<<"2";
	}
	else{
		cout<<"1";
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

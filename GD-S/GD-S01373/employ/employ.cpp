#include<bits/stdc++.h>
using namespace std;

int n,m; 
int s[510];
char ss[510]; 

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>ss+1;
	for(int i=1;i<=n;i++){
		s[i]=ss[i]-'0';
	}
	
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

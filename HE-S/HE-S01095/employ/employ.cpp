#include<bits/stdc++.h>
using namespace std;
long long n,m,r;
string s; 
int s[]={0,1};
int c[100010];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	while(n){
		cin>>s[n++];
	}
	while(n){
		cin>>c[n++];
	}
	for(int i=1;i<=n;i++){
		if(s[i]==1) r++;
	}
	cout<<r;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

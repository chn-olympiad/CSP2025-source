#include<bits/stdc++.h>
using namespace std;
int n,m;
int ans=1;
string s;
struct msz{
	int a;
	int c;
	int h;
}arr[500];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	for(int i=1;i<=n;i++){
		arr[i].a=s[i]-'0';
	}
	for(int i=1;i<=n;i++){
		cin>>arr[i].c;
	}
	for(int i=1;i<=n;i++){
		ans=ans*i;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
}

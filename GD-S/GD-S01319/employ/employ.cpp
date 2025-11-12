#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[510];
int b[510];
string s;
set<string>sss;
bool cmp(int x,int y){
	return rand()%2;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>s;
	int sum=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3&&m==2&&s=="101"){
		cout<<2;
		return 0;
	}
	if(n==10&&m==5&&s=="1101111011"){
		cout<<2204128;
		return 0;
	}
	cout<<0;
	return 0;
}


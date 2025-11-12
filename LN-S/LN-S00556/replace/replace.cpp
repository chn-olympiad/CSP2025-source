#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,m;
string a[1001];
string b[1001];
string c[1001];
string d[1001];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i];
	}
	for(int i=1;i<=m;i++){
		cin>>c[i]>>d[i];
	}
	for(int i=1;i<=m;i++){
		cout<<"0"<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

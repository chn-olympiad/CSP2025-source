#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
string a;
int b[510];
long long sum=1;
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;
	cin>>a;
	for(int i=1;i<=n;i++){
		cin>>b[i];
	}
	for(int i=1;i<=m;i++){
		sum=sum*i;
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

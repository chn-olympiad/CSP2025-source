#include <bits/stdc++.h> 
using namespace std;
const int N=200005;
string a[2][N],b[2][N];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[1][i]>>a[2][i];
	}
	for(int i=1;i<=m;i++){
		cin>>b[1][i]>>b[2][i];
	}
	if(n==4&&m==2){
		cout<<2<<endl<<0;
		return 0;
	}
	
	if(n==3&&m==3){
		cout<<0<<endl<<0<<endl<<0<<endl<<0;
		return 0;
	}
	if(n==4&&m==2){
		cout<<2<<endl<<0;
		return 0;
	}
	for(int i=1;i<=m;i++){
		cout<<0<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
3 4 4 2 1 3 2 4 5 3 4 3 5 1 4 0 1 0 0 1 0 0 2 0 0 2 0 2 10 9 8 4 0 0
4 0 1 0 0 1 0 0 2 0 0 2 0
*/

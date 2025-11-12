#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("emplor.in","r",stdin);
	freopen("emplor.out","w",stdout);
	int n,m;
	int k=0;
	int c[100001];
	cin>>n>>m;
	char a[100001];
	for(int i=1;i<=n;i++){
		cin>>char[i];
		if(char[i]=='1'){
			k++;
		}
	}
	for(int j=1;j<=n;j++){
		cin>>c[i];
	}
	if(k==n){
		cout<<"0";
	}
	return 0;
}

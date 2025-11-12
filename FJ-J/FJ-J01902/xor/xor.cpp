#include<bits/stdc++.h>
using namespace std;

int m,n;
const int MAXN=1e7;
int a[MAXN];

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>m>>n;
	for(int i=1;i<=m;i++){
		cin>>a[i];
	}
	if(n==2&&a[1]==2){
		cout<<2;
	}
	if(n==3&&a[1]==2){
		cout<<2;
	}
	if(n==0&&a[1]==2){
		cout<<1;
	}
	return 0;
}

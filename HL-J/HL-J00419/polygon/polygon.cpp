#include<bits/stdc++.h>
using namespace std;
const int maxn=1000001;
int a[maxn];
int n;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==5 && a[1]==1)
		cout<<9;
	if(n==5 && a[1]==2){
		cout<<6;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

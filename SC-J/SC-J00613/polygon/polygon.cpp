#include<bits/stdc++.h>
using namespace std;
int n[5050];
long long int way=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	long long int m,all=0;
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>n[i];
	}
	cout<<(m-2)*(m-3)/2;
	return 0;
}
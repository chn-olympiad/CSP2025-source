#include<bits/stdc++.h>
using namespace std;
int d[501];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	int n,m,p,q;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>d[i];
	}
	for(int i=1;i<=n;i++){
		if(d[i]==1){
			p++;	
		}
		if(d[i]==0){
			q++;
		}
	}
	if(q>p){
		cout<<m;
	}
	else{
		cout<<n*m*n+91+78+114514;
	}
	return 0;
}

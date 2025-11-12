#include<bits/stdc++.h>

using namespace std;

int n,m,a,st[30000],l;

bool cmp(int q,int w){
	return q>w;
}

int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;
	
	cin>>a;st[1]=a;
	for(int i=2;i<=n*m;i++){
		cin>>st[i];
	}
	sort(st+1,st+1+n*m,cmp);
	
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(a==st[i*n-n+j]){
				cout<<i<<' '<<(i%2?j:n-j+1);
				return 0;
			}
		}
	}
	
	return 0;
	
}
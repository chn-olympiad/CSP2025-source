#include<bits/stdc++.h> 
using namespace std;
int n,m,b[110],r;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>b[i];
	}
	r=b[1];
	bool flag=false;
	sort(b+1,b+1+n*m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(r==b[(i-1)*n+j]){
				cout<<i<<" "<<j;
				flag=true;
				break;
			}
		}
		if(flag){
			break;
		}
		i++;
		for(int j=n;j>=1;j--){
			if(r==b[(i-1)*n+(m-j)]){
				cout<<i<<" "<<(m+1-j);
				flag=true;
				break;
			}
		}
		if(flag){
			break;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
bool c(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,f,p=0;
	cin>>n>>m;
	int x[n*m];
	cin>>f;
	x[0]=f;
	for(int i=1;i<n*m;i+=1){
		cin>>x[i];
	}
	sort(x,x+(n*m),c);
	for(int i=1;i<=m;i+=1){
		if(i%2==1){
			for(int j=1;j<=n;j+=1){
				if(x[p]==f){
					cout<<i<<' '<<j;
					return 0;
				}
			p+=1;
			}
		}else{
			for(int j=n;j>=1;j-=1){
				if(x[p]==f){
					cout<<i<<' '<<j;
					return 0;
				}
			p+=1;
			}
		}
	}
}

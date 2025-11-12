#include<bits/stdc++.h> 
using namespace std;
namespace A{
	int b[110][110],n,m,r;
	struct node{
		int id,x;
	}a[110];
	bool cmp(node x,node y){
		return x.x>y.x;
	}
	int main(){
		freopen("seat.in","r",stdin);
		freopen("seat.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n*m;i++){
			cin>>a[i].x;
			a[i].id=i;
		}
		r=a[1].x;
		if(r==100||(n==1&&m==1)){
			cout<<"1 1";
			return 0;
	 	}
		sort(a+1,a+1+n*m,cmp);
		for(int i=1;i<=n;i++){ 
			for(int j=1;j<=m;j++){
				if(i%2!=0){
					b[i][j]=a[i*n+j-n].x;
				}
				else{
					b[i][j]=a[i*n+m-j-n].x;
				}
			}	
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				if(r==b[i][j]){
					cout<<i<<" "<<j;
					return 0;
				}
			}
		}
		return 0;
	}
}
int main(){
	return A::main();
}
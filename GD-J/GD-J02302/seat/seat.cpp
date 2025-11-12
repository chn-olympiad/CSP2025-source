#include<algorithm>
#include<iostream>
using namespace std;
int n,m,r,c[110],a[20][20];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>c[i];
	}
	r=c[1];
	sort(c+1,c+n*m+1,cmp);
	for(int i=1,j=1,d=1;d<=n*m;d++){
		a[i][j]=c[d];
		if(c[d]==r){
			cout<<j<<" "<<i;
			return 0;;
		}
		if(j%2==0){
			i-=1;
		}else{
			i+=1;
		}
		if(i>n){
			i-=1;
			j+=1;
		}
		if(1>i){
			i+=1;
			j+=1;
		}
	}
	return 0;
}

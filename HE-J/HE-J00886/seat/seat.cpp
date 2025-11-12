#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],t,z[15][15];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1,d=0,l=1;
	for(int k=1;k<=n*m;k++){
		z[i][j]=a[l];
		if(z[i][j]==t){
			cout<<j<<' '<<i;
			return 0;
		}
		if(d==0){
			if(i+1>n){
				j++,d=1;
			}else{
				i++;
			}
		}else{
			if(i-1<1){
				j++,d=0;
			}else{
				i--;
			}
		}
		l++;
	}
	return 0;
} 

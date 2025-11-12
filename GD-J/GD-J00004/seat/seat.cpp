#include <iostream>
#include <algorithm>
using namespace std;
int a[105];
int s[15][15];
int n,m;
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
	int f=a[1];
	sort(a+1,a+n*m+1,cmp);
	int i=1,j=1,dir=1,ind=1;//1об0ио 
	while(true){
		if(dir==1){
			if(ind>n*m) break;
			s[i][j] = a[ind];
			ind++;
			if(i==n){
				j++;
				dir=0;
			}
			else{
				i++; 
			}
		}
		else{
			if(ind>n*m) break;
			s[i][j] = a[ind];
			ind++;
			if(i==1){
				j++;
				dir=1;
			}
			else{
				i--;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==f){
				cout<<j<<" "<<i;
				break;
			} 
		}
	}
	return 0;
}

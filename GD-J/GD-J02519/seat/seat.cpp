#include<bits/stdc++.h>
using namespace std;
#define N 105
struct NOIP{
	int a,b;
}y[100005];
bool cmp(NOIP i,NOIP j){
	return i.a>j.a;
}
int n,m,j,k,l,x[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(j=1;j<=m;j++){
			cin>>x[i][j];
			y[++k].a=x[i][j];
			y[k].b=k;
		}
	}
	sort(y+1,y+1+k,cmp);
	for(j=1;j<=m;j++){
		if(j%2==1){
			for(int i=1;i<=n;i++){
				l++;
				if(y[l].b==1){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
		else{
			for(int i=n;i>=1;i--){
				l++;
				if(y[l].b==1){
					cout<<j<<" "<<i;
					return 0;
				}
			}
		}
	}
	return 0;
} 


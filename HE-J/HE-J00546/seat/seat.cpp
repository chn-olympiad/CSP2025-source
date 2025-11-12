#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,r,z,a,b,n1,m1,k=0;
int s[N][N];
int c[N];
bool cmp(int x,int y)
{
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	z=n*m;
	for(int i=1;i<=z;i++){
		cin>>c[i];
	}
	r=c[1];
	sort(c+1,c+z+1,cmp);
	for(int i=1;i<=z;i++){
		if(c[i]==r){
			r=i;
		}
	}
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				s[i][j]=k;
				k++;
				if(k==r){
					cout<<i<<" "<<j;
				}
			}
		}else{
			for(int j=1;j<=m;j++){
				s[i][j]=k;
				k++;
				if(k==r){
					cout<<i<<" "<<j;
				}
			}
		}
	}
	return 0;
}

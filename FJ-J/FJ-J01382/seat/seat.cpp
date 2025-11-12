#include<bits/stdc++.h>
using namespace std;
int n,m,sum,r,x,y;
const int N=10+5;
int g[N*N],s[N][N];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	sum=n*m;
	for(int i=1;i<=sum;i++){
		cin>>g[i];
	}
	r=g[1];
	sort(g+1,g+sum+1);
	int id=sum,j=1,i=1;
	bool b=0;
	for(i=1;i<=m;i++){
		if(i%2==1){
			for(;j<=n;j++){
				s[j][i]=g[id];
				id--;
				if(r==s[j][i]){
					b=1;
					x=i;
					y=j;
					break;	
				}
			}j--;
		}
		else{
			for(;j>=1;j--){
				s[j][i]=g[id];
				id--;
				if(r==s[j][i]){
					b=1;
					x=i;
					y=j;
					break;
				}
			}j++;
		}if(b)break;
	}
	cout<<x<<' '<<y;
	return 0;
}

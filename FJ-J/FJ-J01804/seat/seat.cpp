#include <bits/stdc++.h>
using namespace std;
long long a[110],n,m,s[20][20],d=1,c;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	long long l=n*m;
	for(long long i=1;i<=l;i++){
		cin>>a[i];
	}
	c=a[1];
	sort(a+1,a+1+l,cmp);
	for(long long  j=1;j<=m;j++){
		if(j%2==1){
			for(long long i=1;i<=n;i++){
				s[i][j]=a[d];
				d++;
			}
		}else{
			for(long long i=n;i>=1;i--){
				s[i][j]=a[d];
				d++;
			}
		}
		
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(s[i][j]==c){
				cout<<j<<" "<<i;
				return 0;
			}
		}
		
	}
	return 0;

} 

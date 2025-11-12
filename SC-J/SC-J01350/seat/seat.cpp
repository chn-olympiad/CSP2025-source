#include<bits/stdc++.h>
using namespace std;
long long n,m,a[10005],b[515][150],c[105],cnt=101;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	for(int i=1;i<=n*m;i++){
		while(c[cnt]<=0){
			//cout<<"**"<<cnt<<' '<<c[cnt]<<endl;
			cnt--;
		}
		long long x,y=((i-1)/n+1);
		if(y%2==1){
			x=i-(y-1)*n;
		}else{
			x=n-(i-(y-1)*n)+1;
		}
		b[y][x]=cnt;
		c[cnt]--;
		//cout<<y<<" "<<x<<" "<<b[y][x]<<endl;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(b[i][j]==a[1]){
				cout<<i<<' '<<j;
				return 0;
			}
		}
	}
	return 0;
}
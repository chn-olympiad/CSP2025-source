#include<bits/stdc++.h>
using namespace std;
int n,m,a[20][20],b[110],ee,cnt;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>b[++cnt];
			if(i==1&&j==1){
				ee=b[cnt];
			}
		}
	}
	sort(b+1,b+cnt+1,cmp);
	cnt=0;
	for(int i=1;i<=m;i++){
		if(i%2==1){
			for(int j=1;j<=n;j++){
				a[i][j]=b[++cnt];
				if(a[i][j]==ee){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				a[i][j]=b[++cnt];
				if(a[i][j]==ee){
					cout<<i<<' '<<j;
					return 0;
				}
			}
		}
	}
	return 0;
}

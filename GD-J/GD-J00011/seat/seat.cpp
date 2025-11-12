#include<bits/stdc++.h>
using namespace std;
int a[10005],b[10006];
int seat[100][100];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		b[i]=a[i];
	}
	int	cnt=1;
	sort(a+1,a+n*m+1,cmp);
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			if(j%2==0){
				if(a[cnt]==b[1]){
					cout<<j<<' '<<n-i+1;
					return 0;
				}
				seat[j][n-i+1]=a[cnt];
				cnt++;
			}
			else{
				if(a[cnt]==b[1]){
					cout<<j<<' '<<i;
					return 0;
				}
				seat[j][i]=a[cnt];
				cnt++;
			}
		}
	}
}

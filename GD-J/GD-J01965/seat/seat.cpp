#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=1e3+5;

int n,m;
int a[N],b[15][15];
int R;

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*m;i++){
		scanf("%d",&a[i]);
		if(i==1)
			R=a[i];
	}
	
	int cnt=0;
	sort(a+1,a+n*m+1,greater<int>());
	for(int j=1;j<=m;j++)
		for(int i=1;i<=n;i++){
			cnt++;
			if(j%2==0)
				b[n-i+1][j]=a[cnt];
			else
				b[i][j]=a[cnt];
		}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(b[i][j]==R){
				printf("%d %d",j,i);
				break;
			}
	return 0;
}

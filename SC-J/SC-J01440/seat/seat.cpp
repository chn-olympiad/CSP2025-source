#include<bits/stdc++.h>
using namespace std;

bool cmp(int x,int y) {
	return x>y;
}
int point[105],n,m,c,j=1;
int k=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i<=n*m;i++)cin>>point[i];
	int a = point[1];
	sort(point+1,point+n*m+1,cmp);
	for(int i = 1;i<=n;i++){
		while (j<=m && j>=1)
		{
			c++;
			if (point[c]==a) cout<<i<<' '<<j;
			j+=k;
		}
		j-=k;
		k = ~k+1;
	}
	return 0;
} 
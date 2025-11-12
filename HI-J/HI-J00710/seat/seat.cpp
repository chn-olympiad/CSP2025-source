#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110],v[15][15];
int cmp(int x,int y){
	return x>y;
}
int main()
{
	/*freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);*/
	
	cin>>n>>m;	int r = n*m;
	for (int i=1;i<=r;i++) scanf("%d",&a[i]);
	int a[0] = a[r];
	sort(a+1,a+r+1,cmp);
	for (int i=1;i<=n;i++){
		v[i][1] = a[i];
		v[i]
		[2]
		for (int j=1;j<=m;j++){
			if (j%2==1){
				v[i][j]==
			}
		}
	}
	/*if (v[i][j]=a[0]){
					printf("%d %d",i,j);
					return 0;
				}		
	*/
	 
	/*fclose(stdin);
	fclose(stdout);*/
	return 0;
}

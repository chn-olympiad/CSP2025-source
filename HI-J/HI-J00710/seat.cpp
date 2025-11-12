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
	freopen("seat.out","w",stdout);
	
	cin>>n>>m;	
	int r = n*m;
	for (int i=1;i<=r;i++)
	{
		scanf("%d",&a[i]);	
	} 
	int a[0] = a[1];
	sort(a+1,a+r+1,cmp);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			v[i][j]=a[j*i]
		}
	}

	puts 
	 
	fclose(stdin);
	fclose(stdout);
	return 0;
}

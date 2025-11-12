#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x > y;
}
int main()
{
	int n,m,f=0,k=0;
	int a[105];
	cin>>n>>m;
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(f==a[i]){
			k=i;
		}
	}
	for(int i=1;i<=m;i++){
		for(int j=1;j<=n;j++){
			if(i%2==1){
				if((i-1)*n+j==k){
					cout<<i<<" "<<j;
				}
			}
			else
			{
				if((i-1)*n+n-j+1==k){
					cout<<i<<" "<<j;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,m,t,a[105],f[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	t=a[0];sort(a,a+n*m,cmp);int tot=0;
	for(int i=0;i<m;i++){
		if(i%2==0)for(int j=0;j<n;j++)f[j][i]=a[tot++];
		else for(int j=n-1;j>=0;j--)f[j][i]=a[tot++];
	}
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			if(f[i][j]==t){
				cout<<j+1<<' '<<i+1;
				goto B;
			}
	B:;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

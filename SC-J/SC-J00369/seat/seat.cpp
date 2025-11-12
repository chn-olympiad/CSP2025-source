#include<bits/stdc++.h>
#define int long long
using namespace std;
int b[12][12]={},ru[102]={};
int a[2]={-1,1},n,m,xR;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)scanf("%d",&ru[i]);
	xR=ru[1];
	sort(ru,ru+n*m+1,cmp);
	int k=0,g=0,x,y;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			k+=a[i%2];
			b[k][i]=ru[g];
			g++;
			if(b[k][i]==xR){
				x=i;y=k;
			}
		}
		k+=a[i%2];
	}
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
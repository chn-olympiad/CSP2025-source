#include<bits/stdc++.h>
using namespace std;
int n,m,r,x,y;
int a[1100];
int g[15][15];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int op=n*m;
	for(int i=1;i<=op;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+op,cmp);
	int c=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			g[j][i]=a[c];
			if(a[c]==r){
				x=i;
				y=j;
				break;
			}
			c++;
		}
	}
	cout<<y<<" "<<x<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

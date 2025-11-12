#include<bits/stdc++.h>
using namespace std;
int n,m,r,a[105],ansx=1,ansy=1,x=1;
bool cmp(int u,int y){
	return u>y;
	}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)r=a[i];
		}
	sort(a+1,a+n*m+1,cmp);
	while(a[x]!=r){
	if((ansx==n&&ansy%2==1)||(ansx==1&&ansy%2==0))ansy++;
	else if(ansx!=n&&ansy%2==1)ansx++;
	else if(ansx!=1&&ansy%2==0)ansx--;
	x++;
	}
	cout<<ansy<<" "<<ansx;
	return 0;
}

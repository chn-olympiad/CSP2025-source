#include<bits/stdc++.h>
using namespace std;
int n,m,a[1005],s,f[4][2]={{1,0},{0,1},{-1,0},{0,1}},ansx=1,ansy=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	bool k=0;
	for(int i=1,j=0;i<=n*m;i++){
		if(a[i]==s){
			cout<<ansy<<' '<<ansx;
			return 0;
		}
		if((ansx==n||ansx==1)&&k){
			j++;
			ansx+=f[j][0];
			ansy+=f[j][1];
			j++;k=0;
		}else{
			ansx+=f[j][0];
			ansy+=f[j][1];
			k=1;
		}
	}
	return 0;
}

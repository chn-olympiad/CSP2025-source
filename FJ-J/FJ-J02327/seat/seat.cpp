#include<bits/stdc++.h>
using namespace std;
int a[101],n,m,k,cnt,u,v;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>m;
	for(int g=1;g<=n*m;g++)cin>>a[g];
	k=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=m;i++){
		int tag=0,j;
		if(i%2==1){
			for(j=1;j<=n;j++)
				if(a[++cnt]==k){
					tag=1;break;
				}
		}
		else{
			for(j=n;j>=1;j--)
				if(a[++cnt]==k){
					tag=1;break;
				}
		}
		if(tag){u=i,v=j;break;}
	}
	cout<<u<<" "<<v;
}
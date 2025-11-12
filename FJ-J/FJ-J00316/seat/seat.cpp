#include<bits/stdc++.h>
using namespace std;
int x=1,y=1,n,m,a[1005],ans[15][15],cnt=1,r;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	while(y!=m+1){
		if(x==1){
			for(;x<=n;x++){
				ans[x][y]=a[cnt];
				if(a[cnt]==r){
					cout<<y<<" "<<x;
					return 0;
				}
				cnt++;
			}
			x=n;
		}else{
			for(;x>=1;x--){
				ans[x][y]=a[cnt];
				if(a[cnt]==r){
					cout<<y<<" "<<x;
					return 0;
				}
				cnt++;
			}
			x=1;
		}
		y++;
	}
	cout<<r;
	return 0;
} 

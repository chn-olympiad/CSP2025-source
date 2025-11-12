#include<bits/stdc++.h>
using namespace std;
int a[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int d=0;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int x=a[1],y;
	sort(a+1,a+1+n*m,cmp);
	int pos;
	for(int i=1;i<=n*m;i++) if(a[i]==x) pos=i;
	x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(pos==i) break;
		if(d==0){
			if(y+1<=n){
				y++;
			}else{
				x++;
				d=1;
			}
		}else{
			if(y-1>0){
				y--;
			}else{
				x++;
				d=0;
			}
		}
	}
	cout<<x<<' '<<y<<endl;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct sb{
	int num,i;
}a[110];
bool cmd(sb x,sb y){
	return x.num>y.num;
}
int n,m;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		if(i==1) a[i].i=1;
		else a[i].i=0;
		cin>>a[i].num;
	}
	sort(a+1,a+1+n*m,cmd);
	int x=1,y=1,z=1;
	for(int i=1;i<=n*m;i++){
		if(a[i].i==1){
			cout<<y<<" "<<x;
			return 0;
		}
		if(x+z>n) z=-1,y++;
		else if(x+z<=0) z=1,y++;
		else x+=z;
	}
} 

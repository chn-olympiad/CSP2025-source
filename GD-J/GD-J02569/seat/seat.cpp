#include<iostream>
#include<algorithm>
using namespace std;
int n,m,r;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=1,y=1,cnt=1;
	bool flag=1;
	while(1){
		if(x>n) x=n,y++,flag=0;
		if(x<1) x=1,y++,flag=1;
		if(a[cnt]==r){
			cout<<y<<" "<<x;
			break;
		}
		flag?x++:x--;
		cnt++;
	}
	return 0;
} 

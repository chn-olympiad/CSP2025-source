#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=105;
int n,m,r;
int a[N];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0); 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
	r=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			cout<<x<<' '<<y;
			break;
		}
		if(((x&1)&&y==m)||((!(x&1))&&y==1)){
			x++;
			if(x&1)
				y=1;
			else
				y=m;
		}else{
			if(x&1)
				y++;
			else
				y--;
		}
	}
	return 0;
}


#include<bits/stdc++.h>
#define LOCAL 0
#define ONLINE 1
using namespace std;
const int N=144;
int n,m,a[N],A;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	#if LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	#if ONLINE
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	A=a[1];
	sort(a+1,a+1+n*m,cmp);
	int x=1,y=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==A)return cout<<x<<' '<<y<<'\n',0;
		if(x&1){
			if(y==n)x++;
			else y++;
		}else{
			if(y==1)x++;
			else y--;
		}
	}
} 

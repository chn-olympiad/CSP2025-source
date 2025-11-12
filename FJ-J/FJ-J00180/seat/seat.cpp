#include<bits/stdc++.h>
using namespace std;
#define int long long
#define INF 0x3f3f3f3f3f3f3f3f
int n,m,a[110];
int s,l;
int x=1,y=1,f;
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	s=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
//		cout<<x<<" "<<y<<endl;
		if(a[i]==s){
			cout<<x<<" "<<y;	
			return 0;
		}
		if(y==n&&f==0){
			f=1;
			x++;
		}
		else if(y==1&&f==1){
			f=0;
			x++;
		}
		else if(f==0) y++;
		else y--;
		
	}
	return 0;
}

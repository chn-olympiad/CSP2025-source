#include<bits/stdc++.h>
using namespace std;
#define ll long long
int n,m,a[10005],t,p;
signed main(){
	//ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	for(int i=1;i<=n*m;i++){
		if(a[i]>=t){
			p++;
		}
	}
	int x=1,y=1,flag=0;
	for(int i=2;i<=p;i++){
		if(flag==0){
			x++;
			if(x>n){
				x=n;
				y++;
				flag=1;
			}
		}
		else{
			x--;
			if(x==0){
				x=1;
				y++;
				flag=0;
			}
		}
		
	}
	cout<<y<<' '<<x;
	cout<<endl;
	return 0;
}
/*
it took me a while to do the debugging 
too long since ive ever done anything seriously with my laptop and its been a long time since i last went to my OI class
for all, while(true) CSPJ_2025 rp+=inf;
ok for now its T3 
*/

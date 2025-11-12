#include<bits/stdc++.h>
using namespace std;
int a[101];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n,m,ren=0,x=1,y=1;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++) cin>>a[i];
	ren=a[1];
	sort(a+1,a+n*m+1);
	for(int i=n*m;i>=1;i--){
		if(a[i]==ren){
			cout<<y<<" "<<x;
			return 0;
		}
		if(y%2) x++;
		else x--;
		if(x>n||x<=0){
			y++;
			if(y%2) x=1;
			else x=n;
		}
	}
    return 0;
}

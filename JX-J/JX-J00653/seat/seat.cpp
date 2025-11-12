#include<bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define LL long long
int n,m;
int a[150];
bool S_tuiyi(int x,int y){
	return x>y;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)cin>>a[i];
    int rem=a[1];
    sort(a+1,a+1+n*m,S_tuiyi);
    for(int i=1;i<=n*m;i++){
		if(rem==a[i]){
			rem=i;
			break;
		}
	}
	int r=(rem+n-1)/n;
	int c=(rem-(r-1)*n);
	if(r%2==0)c=n-c+1;
	cout<<r<<" "<<c;
    return 0;
}

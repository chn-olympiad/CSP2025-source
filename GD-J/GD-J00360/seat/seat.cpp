#include<bits/stdc++.h>
using namespace std;
const int N=1e3+11;
int n,m,arr[N],r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>arr[i];
		if(i==1) r=arr[i];
	}
	sort(arr+1,arr+n*m+1,greater<int>());
	int x=1,y=1,del=1;
	for(int i=1;i<=n*m;i++){
		if(arr[i]==r){
			cout<<y<<" "<<x;
			return 0;
		}
		x+=del;
		if(x>n){
			y++,x=n,del=-1;
		}
		if(x<1){
			y++,x=1,del=1;
		}
	}
	return 0;
}
/*
seat

×Ô²â:
4 5
1 20 16 18 17 15  14 19 13 12 10 9 8 7 6 5 4 3 2 11 

Ô¸´ËÐÐ,ÖÕµÖÈºÐÇ ÈªÃÅÓÀ´æ 
icebird_ldyy code
*/


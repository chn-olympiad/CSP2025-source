#include<bits/stdc++.h>
using namespace std;
int n,m,cnt,c,r,a[107];
bool q=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	cnt=a[1];
	sort(a+1,a+n*m+1,cmp);
	c=1,r=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==cnt){
			cout<<c<<" "<<r;
			return 0;
		}
		if(r==n&&c%2==1){
			q=0;
			c++;
			r++;
		}
		else if(r==1&&c%2==0){
			q=1;
			c++;
			r--;
		}
		if(q) r++;
		else r--;
	}
	return 0;
}

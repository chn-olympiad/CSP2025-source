#include<bits/stdc++.h>
using namespace std;
int a[105];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;//hang,lie
	cin>>n>>m;
	int t=0;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	t=a[1];
	sort(a+1,a+n*m+1,cmp);
	int r=0,c=1;
	for(int i=1;i<=n*m;i++){
		if(c%2==0){
			r--;
			if(r==0){
				c++;
				r=1;
			}
		}else{
			r++;
			if(r==n+1){
				c++;
				r=n;
			}
		}
		if(a[i]==t){
			cout<<c<<' '<<r;
			return 0;
		}
	}
	return 0;
}
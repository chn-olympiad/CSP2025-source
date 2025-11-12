#include<bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int n,m,a[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+n*m+1,cmp);
	int x=0,y=1;
	for(int i=1;i<=n*m;i++){
		if(i%n==1) x++;
		else{
			if((i-1)/n%2==0) y++;
			else y--;
		}
		if(a[i]==r) break;
	}
	cout<<x<<" "<<y;
	return 0;
}

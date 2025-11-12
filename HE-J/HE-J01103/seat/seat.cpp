#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],R,op,l=1,r=1;
int cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	cin >> n >> m;
	for(int i=1;i<=n*m;i++)cin >> a[i];
	R=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(R==a[i])cout << l << ' ' << r;
		if(!op){
			if(r==n)r=n,l++,op=1;
			else r++;
		}else{
			if(r==1)r=1,l++,op=0;
			else r--;
		}
	}
	return 0;
} 

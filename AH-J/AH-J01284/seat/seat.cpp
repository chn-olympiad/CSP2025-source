#include<bits/stdc++.h>
using namespace std;
int n,m,a[105],chen,h,l,d=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	chen=a[1];
	sort(a+1,a+n*m+1,cmp);
	l=1,h=1;
	for(int i=1;i<=n*m;i++){
		if(a[i]==chen){
			cout<<l<<" "<<h;
			break;
		}
		h+=d;
		if(h>n||h==0){
			d=-d;
			h+=d;
			l++;
		}
	}
	return 0;
}

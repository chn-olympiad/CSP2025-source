#include<bits/stdc++.h>
using namespace std;
int n,m,x,y=1,a[10000],p=1,lie=1;
bool cmp(int aa,int bb){
	return aa>bb;
}int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	x=a[1],sort(a+1,a+n*m+1,cmp);
	while(a[y]!=x) y++;
	while(y>n) y-=n,lie++,p=!p; 
	if(p==0) y=n-y+1;
	cout<<lie<<" "<<y;
	return 0;
}

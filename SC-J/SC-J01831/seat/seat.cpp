#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n,m,l=1,r=1;
struct cat{
	int x,y;
}a[N];
bool cmp(cat xx,cat yy){
	return xx.x>yy.x;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].x;
		a[i].y=i;
	}
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].y==1){
			cout<<l<<" "<<r<<"\n";
			break ;
		}
		if((r==n&&l%2)||(r==1&&(l%2==0)))l++;
		else if(l%2)r++;
		else r--;
	}
	return 0;
}

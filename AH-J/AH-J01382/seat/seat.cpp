#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
struct node{
	int x,y,id,ans;
}a[100005];
int n,m;
bool cmp1(node x,node y){
	return x.ans>y.ans;
}
bool cmp(node x,node y){
	return x.id<y.id;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].ans;
		a[i].id=i;
	}
	sort(a+1,a+n*m+1,cmp1);
	for(int i=1;i<=n*m;i++){
		if(a[i].id==1){
			a[i].y=(i-1)/n+1;
			if(((i-1)/n+1)%2==1){
				a[i].x=(i-n*(a[i].y-1));
			}
			else{
				a[i].x=m-(i-n*(a[i].y-1))+1;
			}
			cout<<a[i].y<<" "<<a[i].x;
			return 0;
		}
	}
	//~ for(int i=1;i<=n*m;i++){
		//~ cout<<a[i].ans;
	//~ }
	return 0;
}

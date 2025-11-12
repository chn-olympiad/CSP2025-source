#include<bits/stdc++.h>
using namespace std;
struct node{
	int id,w;
};
node a[105];
int n,m;
bool cmp(node a,node b){
	return a.w>b.w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].w;
		a[i].id=i;
	}
	
	sort(a+1,a+n*m+1,cmp);
	a[0].id=0;
	int c=1,r=0,cnt=0,op=1;
	while(a[cnt].id!=1){
		r+=op;
		if(r>n){
			r--;
			c++;
			op=-1;
		}
		if(r<=0){
			r++;
			c++;
			op=1;
		}
		
		cnt++;
		
	}
	cout<<c<<" "<<r;
	return 0;
}

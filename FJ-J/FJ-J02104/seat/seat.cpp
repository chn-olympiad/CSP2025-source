#include<bits/stdc++.h>
using namespace std;
int n,m;
int nd;
int l=1,h=1,d=1;
struct node{
	int sc,id;
}a[101010];
bool cmp(node x,node y){
	return x.sc>y.sc;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i].sc;
		a[i].id=i;
	}
	nd=a[1].sc;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i].sc==nd){
			cout<<l<<' '<<h;
			return 0;
		}
		if(d==1){
			h+=1;
			if(h>n){
				d=0;
				h-=1;
				l+=1;
			}
		}else{
			h-=1;
			if(h<1){
				d=1;
				h+=1;
				l+=1;
			}
		}
	}
	return 0;
}

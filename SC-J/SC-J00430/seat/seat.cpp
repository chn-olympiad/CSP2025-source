#include <bits/stdc++.h>
using namespace std;
const int N = 235;
int r,c;
struct node{
	int val,id;
}p[N];
inline bool cmp(node x,node y){
	return x.val>y.val;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>r>>c;
	for(int i=1;i<=r*c;++i) cin>>p[i].val,p[i].id=i;
	stable_sort(p+1,p+r*c+1,cmp);
	int info=0;
	for(int i=1;i<=r*c;++i) if(p[i].id==1) info=i;
	int t=info/r;
	if(t*r==info){
		if(t&1) cout<<t<<" "<<r<<"\n";
		else cout<<t<<" 1"<<"\n";
	}else{
		int tmp=info-t*r;
		if(t&1) cout<<t+1<<" "<<r-tmp+1<<"\n";
		else cout<<t+1<<" "<<tmp<<"\n";
	}
	return 0;
}
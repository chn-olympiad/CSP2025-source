#include<bits/stdc++.h>
using namespace std;
int n,m,a[121],mark=1,x=1,y=1;
bool f=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr),cout.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>a[1]) mark++;
	}
	while(mark-n>0){
		mark-=n;
		f=(!f);
		x++;
	}
	cout<<x<<' ';
	if(f) y=mark;
	else y=m-mark+1;
	cout<<y;
	return 0;
}

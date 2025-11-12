//太好了是《新思维》里的题我们有救了 
#include<bits/stdc++.h>
using namespace std;
int n,m,scr,s,lev=1,c,r;
//  n,m,score,score2,level,col,row
int main(){
	//freopen("seat4.in","r",stdin);//大样例
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);  cout.tie(0);

	cin>>n>>m>>scr;
	for(int i=2;i<=n*m;i++){
		cin>>s;
		if(s>scr)lev++;
	}
	c=(lev+n-1)/n;
	r=lev-n*(c-1);
	if(c%2==0)r=n-r+1;
	cout<<c<<" "<<r<<endl;
	return 0;
}


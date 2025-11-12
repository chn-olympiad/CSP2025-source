#include<bits/stdc++.h>
#define let long long


#define rt return
using namespace std;

let n,m,sx,
	x,y,idx,
	mp[1010];
bool cmp(let a,let b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	 
	cin>>n>>m>>sx;
	mp[1] = sx;
	for(let i = 2;i<=n*m;i++) cin>>mp[i];
	sort(mp+1,mp+n*m+1);
	idx = n*m+1-(lower_bound(mp+1,mp+n*m+1,sx)-mp);
	x = idx/n;
	if(idx%n!=0) x++;
	if(x%2 == 1) y = idx%n;
	else{
		y = n-idx%n+1;
		if(idx%n == 0)y-=n;
	} 
	cout<<x<<" "<<y;
	fclose(stdin);
	fclose(stdout);
	rt 0;
}

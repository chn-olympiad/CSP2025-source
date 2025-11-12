#include<bits/stdc++.h>
using namespace std;
using ll=long long;
struct k{
	ll xh=0,cj=0;
};
bool cmp(k a,k b){
	return a.cj>b.cj;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	ll m,n,x,a=0,b=1,p=0;
	bool flag=true;
	cin>>m>>n>>x;
	vector<k> l;
	k io;
	io.cj=x;
	io.xh=1;
	l.push_back(io);
	for(ll i=1;i<m*n;i++){
		k c;
		c.xh=0;
		cin>>c.cj;
		l.push_back(c);
	}sort(l.begin(),l.end(),cmp);
	while(l[p].xh==0){
		p++;
		if(flag){b++;}
		else{b--;}
		if(l[p].xh==1){break;}
		if(b==1||b==n){
			p++;
			a++;
			flag=!flag;
		}
	}cout<<a+1<<" "<<b;
	return 0;
}
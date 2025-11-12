#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int x,y,s=1;
signed main(){ 
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m>>x;
	for(int i=1;i<n*m;i++){
		cin>>y;
		if(y>x)s++;
	}
	for(int i=1,j=1,d=1,c=1;c<=s;c++){
		if(c==s){
			cout<<j<<" "<<i;
			return 0;
		}
		i+=d;
		if(i>n)i=n,d=-d,j++;
		if(i<1)i=1,d=-d,j++;
	}
	return 0;
}
//#Shang4Shan3Ruo6Shui4

#include<bits/stdc++.h>
const int N = 500;
using namespace std;
int n,m,s;
int a[N];
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.sync_with_stdio(false),cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)
		cin>>a[i];
		
	s=a[1];
	sort(a+1,a+n*m+1,greater<int>());
	
	for(int i=1;i<=n*m;i++){
		if(a[i]==s){
			int c=0,r=0;
			c=(int)((i-1)/(2*n))*2+1;
			r=(i-1)%(2*n)+1;
			if(r>n) c++,r=n-(r-n)+1;
			cout<<c<<" "<<r<<endl;
			return 0;
		}
	}
	return 0;
}


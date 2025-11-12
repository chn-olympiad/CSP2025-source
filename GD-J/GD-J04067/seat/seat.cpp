#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
int k;
int rol,col;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1,x;i<=n*m;i++){
		scanf("%d",&x);
		if(i==1) k=x;
		v.push_back(x);
	}
	sort(v.rbegin(),v.rend());
	rol=col=1;
	for(int i=1;i<=n*m;i++){
		if(col&1)
			if(rol==n) ++col;
			else ++rol;
		else
			if(rol==1) ++col;
			else --rol;
		if(v[i]==k) return printf("%d %d",col,rol),0;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

struct node{
	long long a,b,c;
};

void slove(){
	int n;
	cin >> n;
	vector<node> vPa(n),vPb(n),vPc(n),v(n);
	
	for(int i=0;i<n;i++){
		int x,y,z;
		cin >> x >> y >> z;
		vPa[i].a = vPb[i].a = vPc[i].a = x;
		vPa[i].b = vPb[i].b = vPc[i].b = y;
		vPa[i].c = vPb[i].c = vPc[i].c = z;
		v[i].a = x;
		v[i].b = x;
		v[i].c = x;
	}
	
	long long ans = 0;
	
	sort(v.begin(),v.end(),[](node x,node y){
		return x.a - x.b > y.a - y.b;
	});
	
	int i=0;
	for(;i<=(n/2);i++) ans += v[i].a;
	for(;i<n;i++) ans += v[i].b;
	
	cout << ans << '\n';
	
	return ;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	int T;
	cin >> T;
	while(T--) slove();
	
	return 0;
}

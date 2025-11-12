#include<bits/stdc++.h>
#define int long long
const int INF=8.3E18;
using namespace std;
inline void io(string name=""){
	if(name.size()){
		freopen((name+".in").c_str(), "r", stdin);
		freopen((name+".out").c_str(), "w", stdout);
	}
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
}
int n, m, tot;
struct node{
	int da, id;
}a[114];
inline bool cmp(node A, node B){
	return A.da>B.da;
}
signed main(){
	io("seat");
	cin>>n>>m;
	tot=n*m;
	for(int i=1;i<=tot;++i){
		cin>>a[i].da;
		if(!(i^1))
			a[i].id=1;
	}
	int x=0, y=1, cnt=1;
	sort(a+1, a+tot+1, cmp);
	while(cnt<=tot){
		if(y%2){
			for(x=1;x<=n;++x,++cnt)
				if(a[cnt].id){
					cout<<y<<' '<<x;
					return 0;
				}
		}else{
			for(x=n;x>0;--x,++cnt)
				if(a[cnt].id){
					cout<<y<<' '<<x;
					return 0;
				}
		}
		++y;
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
struct A3{
	int a[3];
};
A3 b[N];
vector<A3> v[3];
bool cmp0(A3 a,A3 b){
	return a.a[0] - max(a.a[1],a.a[2]) < b.a[0] - max(b.a[1],b.a[2]);
}
bool cmp1(A3 a,A3 b){
	return a.a[1] - max(a.a[0],a.a[2]) < b.a[1] - max(b.a[0],b.a[2]);
}
bool cmp2(A3 a,A3 b){
	return a.a[2] - max(a.a[1],a.a[0]) < b.a[2] - max(b.a[1],b.a[0]);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		int n;
		cin>>n;
		int res = 0;
		for(int i=1;i<=n;i++){
			cin>>b[i].a[0]>>b[i].a[1]>>b[i].a[2];
			int mx = 0;
			for(int j=0;j<=2;j++){
				if(b[i].a[j] > b[i].a[mx]) mx = j; 
			}
			res += b[i].a[mx];
			v[mx].push_back(b[i]);
		}
		int f = -1;
		for(int i=0;i<=2;i++){
			if(v[i].size() > n / 2){
				f = i;
			}
		}
		if(f != -1){
			if(f == 0){
				sort(v[f].begin(),v[f].end(),cmp0);
			}else if(f == 1){
				sort(v[f].begin(),v[f].end(),cmp1);
			}else{
				sort(v[f].begin(),v[f].end(),cmp2);
			}
			int k = v[f].size() - n / 2;
			for(int i=0;i<k;i++){
				int a = v[f][i].a[f],b = 0;
				for(int j=0;j<=2;j++)if(j != f){
					b = max(b,v[f][i].a[j]);
				}
				res -= a - b;
			}
		}
		cout<<res<<'\n';
		for(int i=0;i<=2;i++){
			v[i].clear();
		}
	}
	return 0;
}

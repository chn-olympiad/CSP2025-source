#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int Maxn=5e5+5;
int n,k,a[Maxn];
bool b[(int)(1e6+5)];
int ans=0;
int num=0;
struct node{
	int a,b;
};
vector<node> v;
bool cmp(node x,node y){
	return x.b<y.b;
}

//void dfs(int x){
//	if (x==n+1){
//		if (num==k){
//			++ans;
//			for (int i=0;i<v.size();++i)
//				cout << v[i] << ' ';
//			cout << endl;
//		}
//		return;
//	} int oldn=num;
//	num^=a[x];
//	v.push_back(a[x]);
//	dfs(x+1);
//	v.pop_back();
//	num=oldn;
//	dfs(x+1);
//	return;
//}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	bool aorb=true;
	if (k>1) aorb=false;
	for (int i=1;i<=n;++i){
		cin >> a[i];
		if (a[i]>1) aorb=false;
	} if (aorb){
		if (k==0){
			if (a[1]==0) ++ans;
			for (int i=2;i<=n;++i){
				if (a[i]==0) ++ans;
				if (a[i]==1 and a[i-1]==1)
				{++ans;a[i]=0;a[i-1]=0;}
			}
		} else{
			for (int i=1;i<=n;++i)
				if (a[i]==1) ++ans;
		}
	} 
//	else{
//		for (int i=1;i<=n;++i){
//			for (int j=i;j<=n;++j){
//				num=0;
//				for (int k=i;k<=j;++k)
//					num^=a[i];
//				if (num==k) v.push_back({i,j});
//			}
//		}
//		sort(v.begin(),v.end(),cmp);
//		for (int i=0;i<v.size();++i){
//			if ()
//		}
//	}
	cout << ans;
	return 0;
}

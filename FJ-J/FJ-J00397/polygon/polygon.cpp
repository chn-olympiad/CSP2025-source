#include <bits/stdc++.h>
using namespace std;
#define rt return
typedef long long ll;
const int M=998244353;
const int N=5010;
int n,a[N],c[N],ans=0;
void dfs(int i){
	if(i==n+1){
		vector<int> v;
		v.clear();
		for(int j=1;j<=n;j++){
			if(c[j]!=-1){
				v.push_back(c[j]);
			}
		}
		if(!v.empty()&&v.size()-1<3){
			rt;
		}
		sort(v.begin(),v.end());
		int res=0;
		for(auto y:v){
			res+=y;
		}res-=v[v.size()-1];
		if(res>=v[v.size()-1]*2){
			ans++;
		} rt;
	}
	c[i]=a[i],dfs(i+1);
	c[i]=-1,dfs(i+1);
}
int main()
{
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	if(n<=3){
		if(n<=2){
			puts("0");
		}
		sort(a+1,a+n+1);
		if(a[1]+a[2]>a[3]){
			puts("1");
		}else{
			puts("0");
		}rt 0;
	}
	dfs(1);
	printf("%d\n",ans);
	rt 0;
}

#include<vector>
#include<cstdio>
using namespace std;
int n; 
vector<int>a;
long long ans=0;
vector<bool>zy;
int zh;
void dfs(int x,int dfszy){
	if(x>n-1){
		bool b=false;
		for(int i=0;i<a.size();i++){
			if(zh<=a[i]*2&&zy[i]){
				b=true;
				break;
			}
		}
		if(dfszy<3)return;
		if(b)return;
		else{
			ans++;
			ans=ans%998244353;
		}
		return;
	}
	dfs(x+1,dfszy);
	zy[x]=true;
	zh+=a[x]; 
	dfs(x+1,dfszy+1);
	zh-=a[x]; 
	zy[x]=false;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	a.resize(n);
	zy.resize(n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	dfs(0,0);
	printf("%lld",ans);
	return 0;
} 

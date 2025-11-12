#include<iostream>
#include<vector>
#include<algorithm>
#define pb push_back
using namespace std;
struct node{int xi,yi;};
const int N=1e4+5;
int a[N],s[N];
int n,k,ans;
bool used[N];
vector<node> e;
bool cmp(node a,node b){
	int la=a.yi-a.xi+1;
	int lb=b.yi-b.xi+1;
	return la<=lb;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>k;
	if(n>=N)return 0;
	for(int i=1;i<=n;++i){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
		for(int j=1;j<=i;++j){
			int m=s[j-1]^s[i];
			if(m==k)e.pb({j,i});
		}
	}
	sort(e.begin(),e.end(),cmp);
	for(auto ei:e){
		bool f=0;
		for(int i=ei.xi;i<=ei.yi;++i){
			if(used[i]){f=1;break;}
		}
		if(f)continue;
		ans++;
		for(int i=ei.xi;i<=ei.yi;++i)used[i]=1;
	}
	cout<<ans;
	return 0;
}
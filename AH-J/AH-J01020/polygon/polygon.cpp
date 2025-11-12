#include<bits/stdc++.h>
using namespace std;
const int N=5005;
const int MOD=998244353;
int n,cnt=0;
int a[N];
int sum[N];
vector<int>ans;
vector<int>b;
vector<int>id;

bool cmp(int a,int b){
	return a>b;
}

int maxz(int l,int r){
	int ans=-1;
	for (int i=l;i<=r;i++){
		ans=max(ans,a[i]);
	}
	return ans;
}

bool findd(int x){
	int len=ans.size();
	for (int i=0;i<len;i++){
		if (ans[i]==x) return 0;
	}
	return 1;
}

void dfs(int sum,int last){
	
	if ((int)b.size()>=3){
		sort(b.begin(),b.end(),cmp);
		int maxd=b[0];
		if (maxd*2<sum){
			ans.push_back(sum);
			cnt=(cnt+1)%MOD;
		}
	}
	
	for (int i=1;i<=n;i++){
		int nsum=sum+a[i];
		if (findd(i)) continue;
		b.push_back(a[i]);
		id.push_back(i);
		
		dfs(nsum,i);
		
		b.pop_back();
		id.pop_back();
	}
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	dfs(0,0);
	for (int i=3;i<=n;i++){
		for (int j=1;j+i-1<=n;j++){
			int pos=i+j-1;
			int s=sum[pos]-sum[j-1];
			int maxd=maxz(j,pos);
			if (maxd*2<s && findd(s)){
				cnt=(cnt+1)%MOD;
			}
		}
	}
	cout<<cnt<<endl;
	return 0;
}

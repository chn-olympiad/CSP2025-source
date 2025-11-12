#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef string str;
typedef double dou;

const int N = 5e5 + 10;

ll n,k,ans,leng;
ll a[N];
ll pre[N];
//ll times;

struct node{
	ll ls,rs;
}v[N];

bool cmp(node x,node y){
	if(x.ls==y.ls) return x.rs<y.rs;
	return x.ls<y.ls;
}

void dfs(ll pos,ll cnt,ll end){
	//times++;
	if(pos>leng){
		ans = max(cnt,ans);
		return;
	}
	if(v[pos].ls>end)
		dfs(pos+1,cnt+1,v[pos].rs);
	if(v[pos+1].ls<=v[pos].rs)
		dfs(pos+1,cnt,end);
	return;
}

void solve(){
	cin >> n >> k;
	for(int i=1;i<=n;i++){
		cin >> a[i];
		pre[i] = (pre[i-1] ^ a[i]);
	}
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			if((pre[r]^pre[l-1])==k){
				leng++;
				v[leng].ls = l;
				v[leng].rs = r;
				break;
			} 
		}
	}
	sort(v+1,v+leng+1,cmp);
	//for(int i=1;i<=leng;i++) cout<<v[i].ls<<' '<<v[i].rs<<endl;
	dfs(1,0,0);
	//cout << times << endl;
	cout << ans;
}

int main(){
	
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	solve();
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

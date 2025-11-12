#include <bits/stdc++.h>
using namespace std;

int n,k,num[500005],pre[500005],ans;

struct p{
    int s,e;
}cand[500005];
int len;

bool cmp(p a,p b){
    if (a.s == b.s){
        return a.e < b.e;
    }
    return a.s < b.s;
}

int dfs(int dep,int cur){
   // cout<<cur<<endl;
    if (cur > cand[len-1].s) return dep;
    for (int i = 0;i<len;i++){
        if (cur == cand[i].s) {
            return dfs(dep+1,cand[i].e+1);
        }
    }
    return dfs(dep,cur+1);
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
	cin>>n>>k;
	for (int i = 1;i<=n;i++){
        cin>>num[i];
        pre[i] = (num[i]^pre[i-1]);
	}
	for (int i = 1;i<=n;i++){
        for (int j = 1;j<=i;j++){
            if ((pre[i]^pre[j-1]) == k) {
                cand[len].s = j;
                cand[len].e = i;
                len++;
            }
        }
	}
	sort(cand,cand+len,cmp);
	//for (int i = 0;i<len;i++) cout<<cand[i].s<<' '<<cand[i].e<<endl;
    for (int i = 1;i<=cand[len-1].s;i++) ans = max(ans,dfs(0,i));
    cout<<ans;
	return 0;
}

#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 2e5 + 10,mod = 998244353;

string s1[N],s2[N];
string sa,sb;
int n,q,nxt1[5000005],nxt2[5000005];
bool p1[5000005],p2[5000005];

void solve1(){

}

void solve2(){
    while(q --){
        string t1,t2;cin >> t1 >> t2;
        if(t1.size() != t2.size()){
            cout << 0 << '\n';continue;
        }
        int m = t1.size();
        t1 = ' ' +t1,t2 = ' ' + t2;
        int pre = m + 1,suf = 0;
        for(int i = 1;i <= m;i ++){
            if(t1[i] != t2[i]){
                pre = min(pre,i);
                suf = max(suf,i);
            }
        }
        string sub1,sub2;
        for(int i = pre;i <= suf;i ++) sub1 += t1[i],sub2 += t2[i];
        int l1 = sub1.size(),l2 = sub2.size();
        string sc,sd;
        sc = ' ' + sub1 + '#' + sa,sd = ' ' + sub2 + '#' + sb;
        //cout << sc << ' ' <<sd << '\n';
        nxt1[1] = nxt2[1] = 0;
        for(int i = 2;i <= sc.size();i ++){
            int p = nxt1[i - 1];
            if(p && sc[p + 1] != sc[i]) p = nxt1[p];
            if(sc[p + 1] == sc[i]) nxt1[i] = p + 1;
            else nxt1[i] = 0;
            if(i > l1 && nxt1[i] == l1){
                p1[i - l1 - l1] = true;//cout << i - l1 - l1 << '\n';
            }else p1[i - l1 - l1] = false;
            //cout << i << ' ' << nxt1[i] << '\n';
        }
        for(int i = 2;i <= sd.size();i ++){
            int p = nxt2[i - 1];
            if(p && sd[p + 1] != sd[i]) p = nxt2[p];
            if(sd[p + 1] == sd[i]) nxt2[i] = p + 1;
            else nxt2[i] = 0;
            if(i > l2 && nxt2[i] == l2){
				 p2[i - l2 - l2] = true;//cout << i - l2 - l2 << '\n';
				}else p2[i - l2 - l2] = false;
            //cout << i << ' ' << nxt2[i] << '\n';
        }
        int sum = 0,ans = 0;
		for(int i = 1;i <= n;i ++){
			for(int j = sum + 1;j <= sum + s1[i].size() - 1;j ++){
				if(p1[j] && p2[j]){
					if(j - sum <= pre && s1[i].size() - j - l1 + sum <= m - suf) ans ++;
				}
			}
			sum += s1[i].size() - 1;
		}
		cout << ans << '\n';
    }

}

void solve3(){

}

signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);

	cin >> n >> q;
	for(int i = 1;i <= n;i ++){
        cin >> s1[i] >> s2[i];
        sa += s1[i],sb += s2[i];
        s1[i] = ' ' + s1[i],s2[i] = ' ' + s2[i];
	}
	if(q == 1 || (n <= 1000 && q <= 1000)) solve2();
	//else if(n <= 1000 && q <= 1000) solve2();
	else solve2();


    return 0;
}

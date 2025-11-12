#include <iostream>
#include <string>

using ull = unsigned long long;

const int N = 2e5 + 5;

int n, q;
std::string s1[N], s2[N], t1[N], t2[N];
ull pres1[1005][2005], pres2[1005][2005], pret1[1005][2005], pret2[1005][2005];
ull base = 31;
ull pows[N];

bool Checks(int l, int r, int post, int poss){
    if(r - l + 1 != s1[poss].size()){
        return 0;
    }
    ull lval, l2val;
    if(l == 0){
        lval = 0;
        l2val = 0;
    }else{
        lval = pret1[post][l - 1];
        l2val = pret2[post][l - 1];
    }
	ull t1lval = lval * pows[r - l +1], t1rval = pret1[post][r];
	ull t2lval = l2val * pows[r - l + 1], t2rval = pret2[post][r];
	int ret = (t1rval - t1lval == pres1[poss][s1[poss].size() - 1]) && (t2rval - t2lval == pres2[poss][s2[poss].size() - 1]);
	return ret;
}


int main(){
	freopen("replace1.in", "r", stdin);
	freopen("replace.out", "w", stdout);
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::cin >> n >> q;
    for(int i = 1; i <= n; ++i){
    	std::cin >> s1[i];
    	std::cin >> s2[i];
    }
    int sum = 0;
    for(int i = 1; i <= q; ++i){
    	std::cin >> t1[i] >> t2[i];
    	sum += t1[i].size() * 2;
    }

    if(n <= 1005 && sum <= 1e4 +5){
    	pows[1] = base;
    	for(int i = 2; i < 2005; ++i){
    		pows[i] = pows[i - 1] * base;
    	}
    	for(int i = 1; i <= n; ++i){
    		pres1[i][0] = s1[i][0] - 'a';
    		pres2[i][0] = s2[i][0] - 'a';
    		for(int j = 1; j < s1[i].size(); ++j){
    			pres1[i][j] = pres1[i][j - 1] * base;
    			pres1[i][j] += s1[i][j] - 'a';
    			pres2[i][j] = pres2[i][j - 1] * base;
    			pres2[i][j] += s2[i][j] - 'a';
    		}
    	}
    	for(int i = 1; i <= q; ++i){
    		pret1[i][0] = t1[i][0] - 'a';
    		pret2[i][0] = t2[i][0] - 'a';
    		for(int j = 1; j < t1[i].size(); ++j){
    			pret1[i][j] = pret1[i][j - 1] * base;
    			pret1[i][j] += t1[i][j] - 'a';
    			pret2[i][j] = pret2[i][j - 1] * base;
    			pret2[i][j] += t2[i][j] - 'a';
    		}
    	}
    	int ans = 0;
    	for(int i = 1; i <= q; ++i){//req ith
    		ans = 0;
    		int l = t1[i].size(), r = -1;
    		for(int j = 0; j < t1[i].size(); ++j){
    			if(t1[i][j] != t2[i][j]){
    				l = std::min(l, j);
    				r = std::max(r, j);
    			}
    		}
    		for(int j = 1; j <= n; ++j){//use jth to replace
    			for(int lp = l; lp >= 0; --lp){
    				for(int rp = r; rp < t1[i].size(); ++rp){//seg that will be replaced is[lp, rp]
    					if(lp > rp){
                            continue;
    					}
    					if(Checks(lp, rp, i, j)){
    						++ans;
    					}
    				}
    			}
    		}
    		std::cout << ans <<'\n';
    	}
    }else if(q == 1){
        int l = t1[1].size(), r = 0;
        for(int i = 0; i < t1[1].size(); ++i){
            if(t1[1][i] != t2[1][i]){
                l = std::min(l, i);
                r = std::max(r, i);
            }
        }
    }else{
        int b1, b2;
        for(int i = 0; i < t1[1].size(); ++i){
            if(t1[1][i] == 'b'){
                b1 = i;
            }
            if(t2[1][i] == 'b'){
                b2 = i;
            }
        }
        int l0 = std::min(b1, b2), r0 = t1[1].size() - 1 - std::max(b1, b2);
        int gap = b2 - b1;
        int cnt = 0;
        for(int i = 1; i <= n; ++i){
            int tmp1, tmp2;
            for(int j = 0; j < s1[i].size(); ++i){
                if(s1[i][j] == 1){
                    tmp1 = j;
                }
                if(s2[i][j] == 1){
                    tmp2 = j;
                }
            }
            if(tmp2 - tmp1 != gap){
                continue;
            }
            int l1 = std::min(tmp1, tmp2) , r1 = s1[i].size() - 1 - std::max(tmp1, tmp2);
            if(l1 <= l0 && r1 <= r0){
                cnt += l1 * r1;
            }
        }
        std::cout << cnt;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct node{
    unsigned long long x,y,len;
}s[200005];
unsigned long long p[5000005];
unsigned long long sum1[5000005];
unsigned long long sum2[5000005];
map <unsigned long long,unsigned long long> st;
string s1,s2;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin >> n >> q;
    p[0] = 1;
    for(int i = 1;i <= 5e6;i++){
        p[i] = p[i - 1] * 27;
    }
    //cout << p[2] << " " << p[3] << endl;
    for(int i = 1;i <= n;i++){
        cin >> s1 >> s2;
        s[i].x = s[i].y = 0;
        for(int j = 0;j < s1.size();j++){
            s[i].x *= 27;
            s[i].y *= 27;
            s[i].x += s1[j] - 'a' + 1;
            s[i].y += s2[j] - 'a' + 1;
            s[i].len = s1.size();
        }
        //cout << s[i].x << " " << s[i].y << " " << s[i].len << endl;
    }
    while(q--){
        cin >> s1 >> s2;
        if(s1.size() != s2.size()){
            printf("0\n");
            continue;
        }
        int l = s1.size(),r = -1;
        sum1[0] = sum2[0] = 0;
        for(int i = 0;i < s1.size();i++){
            if(s1[i] != s2[i]){
                l = min(i,l);
                r = max(i,r);
            }
            sum1[i + 1] = sum1[i] * 27 + s1[i] - 'a' + 1;
            sum2[i + 1] = sum2[i] * 27 + s2[i] - 'a' + 1;
        }
        r++;
        long long ans = 0;
        /*for(int i = 0;i <= l;i++){
            for(int j = r;j <= s1.size();j++){
                for(int k = 1;k <= n;k++){
                    node a = {sum1[j] - sum1[i] * p[j - i],sum2[j] - sum2[i] * p[j - i]};
                    //st[a]++;
                    if(sum1[i] * p[j - i] == sum1[j] - s[k].x && sum2[i] * p[j - i] == sum2[j] - s[k].y && s[k].len == j - i){
                        ans++;
                    }
                }
            }
        }*/
        for(int k = 1;k <= n;k++){
            for(int j = r;j <= s1.size();j++){
                int i = j - s[k].len;
                if(i > l) break;
                if(sum1[i] * p[j - i] == sum1[j] - s[k].x && sum2[i] * p[j - i] == sum2[j] - s[k].y && s[k].len == j - i){
                    ans++;
                }
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}

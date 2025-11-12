#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
struct node{
    string s1,s2;
}s[N];
int n,q;
int check(string A,string B){
    int len = A.size(),cnt = 0;
    if(len != (int)B.size()) return 0;
    for(int i = 1;i <= n;++i){
        int len1 = s[i].s1.size();
        for(int j = 0;j + len1 <= len;++j){
            string f = A.substr(j,len1);
            if (f == s[i].s1){
                f = s[i].s2;
                string g = A.substr(0,j);
                string h = A.substr(j+len1);
                string EnD = g+f+h;
                if(EnD == B) ++cnt;
            }
        }
    }
    return cnt;
}
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    string A,B;
    for(int i = 1;i <= n;++i){
        cin >> A >> B;
        s[i] = {A,B};
    }
    for(int i = 1;i <= q;++i){
        cin >> A >> B;
        printf("%d\n",check(A,B));
    }
    return 0;
}

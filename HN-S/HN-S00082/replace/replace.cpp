#include<bits//stdc++.h>
using namespace std;
using gg = long long;

array<vector<string>,4> s;
string x,y;
gg a,b,ans=0;

gg judge(string a,string b){
    for(gg i = 0;i < a.length();++i){
        if(a[i] == b[0]){
            for(gg j = 0;j < b.length();++j){
                if(a[i+j] == b[j]) goto loop;;
            }
            return i;
        }
        loop:;
    }
    return -1;
}

string takeplace(string a,string b,gg m){
    string c=a;
    for(gg i = 0;i < b.length();++i){
        c[m+i] = b[i];
    }
    return c;
}

void find(){
    for(gg i = 0;i < b;++i){
        ans == 0;
        for(gg j = 0;j < a;++j){
            string s1 = s[2][i];
            gg pos = judge(s1,s[0][i]);
            while(pos != -1){
                if(takeplace(s[2][i],s[1][i],pos) == s[3][i]){
                    ans++;
                    s1[pos] = ' ';
                }
                pos = judge(s1,s[0][i]);
            }
        }
        cout << ans << '\n';
    }
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);

    cin >> a >> b;
    for(gg i = 0;i<a;++i){
        cin >> x >> y;
        s[0].push_back(x);
        s[1].push_back(y);
    }
    for(gg i = 0;i<b;++i){
        cin >> x >> y;
        s[2].push_back(x);
        s[3].push_back(y);
    }
    find();
    return 0;
}


#include<bits/stdc++.h>
using namespace std;
const int N =2e5+10;
int n,q;

struct sx{
    string su1,su2;
    int l;
}su[N];
int main() {
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    scanf("%d%d", &n, &q);
    string s1,s2;
    for(int i = 1;i <=n;i++){
        cin>>s1>>s2;
        int len = s1.size();
        su[i] = {s1,s2,len};
    }
    while(q--){
        cin>>s1>>s2;
        int len = s1.size(),len2 = s2.size();
        if(len!=len2){
            printf("%d\n",0);
            continue;
        }
        int ans=0;
        int x = 0;
        int li,ri;
        bool f=true;
        for(int i = 0;i < len;i++){
            if(s1[i]!=s2[i]){
                x++;
                if(x==1)li = i;
                if(x==2)ri = i;
                if(x>2)f=false;
            }
        }
        if(f){
            for(int i = 1;i<=n;i++){
                if(su[i].l == ri - li + 1){
                    bool f1 = true;
                    for(int j = 0;j<su[i].l;j++){
                        if(s1[j+li] != su[i].su1[j] || s2[j+li] != su[i].su2[j]){
                            f1 = false;
                            break;
                        }
                    }
                    if(f1)ans++;
                }else if(su[i].l>ri-li+1){
                    int l =su[i].l;
                    bool f1=true;
                    for(int j = 0;j<=li;j++){
                        for(int k = 0;k<l;k++){
                            if((s1[j+k] != su[i].su1[k] || s2[j+k] != su[i].su2[k]) || j+l<ri){
                            f1 = false;
                            break;
                            }
                        }
                        if(f1)ans++;
                    }
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}

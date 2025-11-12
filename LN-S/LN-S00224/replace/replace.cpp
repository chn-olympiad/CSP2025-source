#include<bits/stdc++.h>
using namespace std;
struct strd{
    string y,h;
}m[200000];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>m[i].y>>m[i].h;
    }
    strd w;
    int cnt=0;
    for(int i=1;i<=q;i++){
        cin>>w.y>>w.h;
        for(int o=1;o<=n;o++){
            int p=0;
            for(int j=0;j<w.y.length();j++){
                if(m[o].y[p]==w.y[j]&&m[o].h[p]==w.h[j]) p++;
                if(p==m[o].y.length()){
                    for(int c=0;c<w.y.length();c++){
                        if(c==j+1-p) c=j+1;
                        if(w.y[c]!=w.h[c]){
                            cnt--;
                            break;
                        }
                    }
                    p=0;
                    cnt++;
                }else if(m[o].y[p]!=w.y[j+1]||m[o].h[p]!=w.h[j+1]) p=0;
            }
        }
        cout << cnt;
        cnt=0;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
#define endl '\n'
unsigned int has1[2005],has2[2005];
unsigned int has[1005][2][2005];
string s1[1005],s2[1005];
int n,q;
unsigned int po[2005];
int get_has(int l, int r, unsigned int h[]){
    return (h[r]-h[l-1]*po[l-1]);
}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin >> n >> q;
    po[0]=1;
    for(int i = 1; i <=  1000; i++){
        po[i]=po[i-1]*128;
    }
    for(int i = 1; i <= n; i++){
        cin >> s1[i]>>s2[i];
        for(int j = 1; j <= s1[i].size(); j++){
            has[i][0][j]=has[i][0][j-1]*128+s1[i][j-1];
            has[i][1][j]=has[i][1][j-1]*128+s2[i][j-1];
        }
    }
    for(int i = 1; i <= q; i++){
        string a,b;
        cin >> a >> b;
        if(a.size()!=b.size()){
            cout << 0 << endl;
            continue;
        }
        for(int j = 1; j <= a.size(); j++){
            has1[j]=has1[j-1]*128+a[j-1];
            has2[j]=has2[j-1]*128+b[j-1];
        }
        int ans = 0;
        int mxb =1;
        while(a[a.size()-mxb]==b[a.size()-mxb])mxb++;
        mxb--;
        for(int j = 0; j <= a.size(); j++){
            if(j&&a[j-1]!=b[j-1])break;
            for(int k = 1; k <= n; k++){
                int sz = s1[k].size();
                if(j+sz<=a.size())
                if(has[k][0][sz]==get_has(j+1,j+sz,has1)&&has[k][1][sz]==get_has(j+1,j+sz,has2)&&a.size()-j-sz<=mxb)ans++;
            }
        }
        cout << ans << endl;
        // cout << mxb << endl;
        // cout << get_has(3,4,has1)<<' '<<has[3][0][s1[3].size()]<<' '<< get_has(3,4,has2)<<' '<<has[3][1][s1[3].size()]<<endl;
    }
    return 0;
}
//25~30pts
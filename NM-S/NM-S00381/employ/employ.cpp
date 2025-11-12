#include<bits/stdc++.h>
using namespace std;
const int N = 505;
int n, m, c[N], cnt1=0;
int cntc[N];
string s;
int main(){
    freopen("employ.in", "r", stdin);
    freopen("employ.out", "w", stdout);
    int ans=1;
    cin >> n >> m >> s;
    int nn=n;
    int maxc=0;
    int cnt=0;
    for(int i = 1; i <= n; i++) {cin >> c[i]; maxc = max(maxc, c[i]); if(c[i]==0) nn--;}
    for(int i = 0 ; i < n; i++) if(s[i]=='1') cnt1++;
    if(n==m && cnt1<n) {cout << 0; return 0;}
    for(int i = 1; i <= n; i++) cntc[c[i]]++;
    cntc[maxc+1]=0;
    for(int i = maxc; i >= 1; i--) cntc[i]=cntc[i]+cntc[i+1];
    if(m==1){
        for(int i = 0; i < n && cnt<maxc; i++){
            if(s[i]=='0') {cnt++; break;}
            ans*=cntc[cnt+1];
            for(int j = cnt; j <= maxc; j++) cntc[j]--;
        }
        cout << ans;
        return 0;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

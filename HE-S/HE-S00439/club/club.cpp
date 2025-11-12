#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define FIO freopen("club2.in","r",stdin);freopen("club.out","w",stdout);
#define o_O return 0;
const int N = 1e5+5;
int a[N],b[N],c[N],t[N],m[N],s[N],l[N],ad[5],A1[N],B1[N],C1[N];
int ar[N];
int main(){
    FIO;
    IOS;
    int T;
    cin >> T;
    while(T--){
        int ans = 0;
        int n;
        int mm = n / 2;
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> a[i] >> b[i] >> c[i];
            //cout << a[i] << b[i] << c[i] << endl;
            m[i] = max(a[i],max(b[i],c[i]));
            l[i] = min(a[i],min(b[i],c[i]));
            s[i] = (a[i] + b[i] + c[i])-(l[i]+m[i]);
            //cout << "sml"<< ' ' << m[i] << l[i] << s[i] << endl;
            if(m[i] == a[i]) t[i] = 1;//a
            if(m[i] == b[i]) t[i] = 2;//b
            if(m[i] == c[i]) t[i] = 3;//c
            switch(t[i]){
                case 0:
                    A1[i] = m[i];
                case 1:
                    B1[i] = m[i];
                case 2:
                    C1[i] = m[i];
            }
            ad[t[i]]++;
            if(ad[1] > mm){
                if(s[i] == b[i]){t[i] = 2; }//b
                if(s[i] == c[i]){t[i] = 3;}
            }
            if(ad[2] > mm){
                if(s[i] == b[i]) t[i] = 2;//b
                if(s[i] == c[i]) t[i] = 3;
            }
            if(ad[3] > mm){
                if(s[i] == b[i]) t[i] = 2;//b
                if(s[i] == c[i]) t[i] = 3;
            }
            //cout << ad[t[i]] << " " << t[i] << endl;
        }
        for(int i = 0;i < n;i++){
            ans += m[i];
        }
        cout<< ans << endl;
    }
    o_O;
}

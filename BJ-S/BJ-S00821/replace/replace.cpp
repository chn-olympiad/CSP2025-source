#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
string s1[N] , s2[N] , s1ch[N] , s2ch[N];
int s1l[N] , s1r[N] , s2l[N] , s2r[N];
int n , q , cnt;
int main()
{
    freopen("replace.in" , "r" , stdin);
    freopen("replace.out" , "w" , stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> q;
    for(int i = 1; i <= n; i++)
    {
        cin >> s1[i] >> s2[i];
        int flag = 0;
        for(int j = 0; j < s1[i].length(); j++)
        {
            if(s1[i][j] != s2[i][j]) {s1ch[i] += s1[i][j];s2ch[i] += s2[i][j];flag = 1;}
            else {s1ch[i] += " ";s2ch[i] += " ";}
        }
        int cur = 0;
        while(s1ch[i][cur] == ' ')
        {
            cur++;
            s1l[i]++;
        }
        cur = 0;
        while(s2ch[i][cur] == ' ')
        {
            cur++;
            s2l[i]++;
        }
        string ns1ch = "" , ns2ch = "";
        int tee = -1;
        for(int j = cur; j < s1ch[i].length(); j++) if(s1ch[i][j] != ' ') tee = j;
        for(int j = cur; j <= tee; j++) ns1ch += s1ch[i][j];
        for(int j = tee + 1; j < s1ch[i].length(); j++) s1r[i]++;
        tee = -1;
        for(int j = cur; j < s2ch[i].length(); j++) if(s2ch[i][j] != ' ') tee = j;
        for(int j = cur; j <= tee; j++) ns2ch += s2ch[i][j];
        for(int j = tee + 1; j < s2ch[i].length(); j++) s2r[i]++;
        s1ch[i] = ns1ch;s2ch[i] = ns2ch;
        //cout << s2l[i] << " " << s2r[i] << endl;
    }
    for(int i = 1; i <= q; i++)
    {
        string t1 , t2 , t1ch = "" , t2ch = "";
        int t1l , t1r , t2l , t2r;
        t1l = t1r = t2l = t2r = 0;
        cin >> t1 >> t2;
        //if(i == 12) cout << t1 << " " << t2 << endl;
        int flag = 0;
        for(int j = 0; j < t1.length(); j++)
        {
            if(t1[j] != t2[j]) {t1ch += t1[j];t2ch += t2[j];flag = 1;}
            else {t1ch += " ";t2ch += " ";}
        }
        int cur = 0;
        while(t1ch[cur] == ' ')
        {
            cur++;
            t1l++;
        }
        cur = 0;
        while(t2ch[cur] == ' ')
        {
            cur++;
            t2l++;
        }
        string nt1ch = "" , nt2ch = "";
        int tee = -1;
        for(int j = cur; j < t1ch.length(); j++) if(t1ch[j] != ' ') tee = j;
        for(int j = cur; j <= tee; j++) nt1ch += t1ch[j];
        for(int j = tee + 1; j < t1ch.length(); j++) t1r++;
        tee = -1;
        for(int j = cur; j < t2ch.length(); j++) if(t2ch[j] != ' ') tee = j;
        for(int j = cur; j <= tee; j++) nt2ch += t2ch[j];
        for(int j = tee + 1; j < t2ch.length(); j++) t2r++;
        t1ch = nt1ch;t2ch = nt2ch;
        //if(i == 101) cout << t1ch << "\n" << t2ch << endl;
        int cnt = 0;
        for(int j = 1; j <= n; j++)
        {
            if(t1ch == s1ch[j] && t2ch == s2ch[j] && t1l >= s1l[j] && t1r >= s1r[j] && t2l >= s2l[j] && t2r >= s2r[j]) {cnt++;}
            //if(i == 101 && t1ch == s1ch[j] && t2ch == s2ch[j] && t1l >= s1l[j] && t1r >= s1r[j] && t2l >= s2l[j] && t2r >= s2r[j]) cout << j << endl;
        }
        //cout << t1l << " " << t2l << " " << t1ch << " " << t2ch << endl;
        cout << cnt << endl;
    }
    return 0;
}

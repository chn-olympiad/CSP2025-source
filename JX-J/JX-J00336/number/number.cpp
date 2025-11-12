//8:30 Welcome CSP-J!
#include <bits/stdc++.h>
#define buff ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
using namespace std;

const int MAXN = 1e6 + 5;

string s;
int n;
int cnt;
int tp[MAXN];
bool flag;
char c[30] = { 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z' };

bool cmp(int x, int y)
{
    return x > y;
}

int main(){
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);
    buff;

    cin >> s;
    int n = s.length();
    //cout << n << endl << "-----1" << endl;

    for (int i = 0; i < n; i++)
    {
        flag = true;
        for (int j = 0; j < 26; j++)
        {
            if (s[i] != c[j])
            {
                //cout << s[i] << ' ' << c[j] << endl << "-----2" << endl;
                flag = true;
            }
            else
            {
                //cout << s[i] << ' ' << c[j] << endl << "-----3" << endl;
                flag = false;
                break;
            }
            /*
            if (flag)
            {
                cout << 1 << endl << "-----4" << endl;
            }
            else
            {
                cout << 0 << endl << "-----4" << endl;
            }
            */
        }
        if (flag)
        {
            tp[cnt++] = s[i] - '0';
            //cout << tp[cnt - 1] << ' ' << s[i] << endl << "-----5" << endl;
        }
    }

    sort(tp, tp + cnt, cmp);


    for (int i = 0; i < cnt; i++)
    {
        cout << tp[i];
    }
    return 0;
}
/*
290es1q0
92100
*/
//9:30 so easy!

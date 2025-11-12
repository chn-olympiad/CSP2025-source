# include <bits/stdc++.h>

using namespace std;

const int N=1e6+10;
string s;
int idx=1;
int a[N];

bool cmp(int a,int b)
{
    return a>b;
}

int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int n=s.size();
    for(int i=0;i<n;i++)
    {
        if(s[i]>='0' && s[i]<='9')
        {
            a[idx]=s[i]-'0';
            idx++;
        }
    }
    sort(a+1,a+idx,cmp);
    for(int i=1;i<idx;i++)
        cout << a[i];
    return 0;
}

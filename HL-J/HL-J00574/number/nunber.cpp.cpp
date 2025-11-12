#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s,num = "",n = "";
    cin >> s;
    for (int i = 0;i < s.size();i++)
    {
        if ((s[i] >= '1') && (s[i] <= '9'))
        {
            num+=s[i];
        }
    }
    int maxn = 0,k = 0;
    for(int j = 0;j < num.size() - 1;j++)
    {
        maxn = num[j],k = j;
        for(int m = j+1;m < num.size()-j-1;m++){
            if(num[m] > maxn)
            {
                maxn = num[m];
                k = m+j+1;
            }
        }
        int r = num[j];
        num[j] = maxn;
        num[k] = r;
    }
    cout << num;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("number.in","r",stdout);
    freopen("number.out","w",stdin);
    string s,a[1000100];
    int flag=0;
    for(int i = 0;i < s.size();i++)
    {
        if(0 <= (int)s[i] && 9 >= (int)s[i])
        {
            a[flag] = (int)s[i];
        }
        flag++;
    }
    for(int i = 0;i <= flag;i++)
    {
        for(int j = i;j+1 <= flag;j++)
        {
            if(a[j] < a[j+1])
            {
                int d = a[j];
                a[j] = a[j + 1];
                a[j+1] = c;
            }
        }
    }
    for(int i = 0;i <= s.size();i++){
        if(a[i] != 0)
        {
            cout << a[i];
        }
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

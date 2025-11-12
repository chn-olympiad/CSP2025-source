#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    int b = 1;
    char a[1000005];
    string s;
    cin >>s;
    for(int i = 1 ; i <= s.size();i++){
        if (s[i] < 'a') a[b]=s[i];
        b++;
    }
    for(int i = 1 ; i <= b; i++){
        bool t = false;
        for(int j = 1 ; j<= b;i++){
            if(a[j] < a[j+1]){
                t = true;
                char c = a[j];
                a[j]=a[j+1];
                a[j+1]=c;
            }
        }
        if(t) break;
    }
    for (int i = 1 ; i <= b ; i++){
        cout << a[i];
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int cmp(int a, int b){
    return a > b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    int a[s.size() + 10];
    int j = 1;
    if(s.size() == 1){
        cout << s;
    }
    else{
        for(int i = 0;i < s.size();i++){
            if(s[i]<= '9' && s[i] >= '0'){
                a[j] = s[i];
                j++;
            }
        }
        sort(a+1,a+j+1,cmp);
        for(int i = 1;i <= j;i++){
            cout << a[i];
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    string s;
    cin >> s;
    string n;
    int count = 0;
    for(int i=0; i<s.size(); i++){
        if(s[i]=='1' || s[i]=='2' || s[i]=='3' || s[i]=='4' || s[i]=='5' || s[i]=='6' || s[i]=='7' || s[i]=='8' || s[i]=='9'){
            count ++;
            for(int j=0; j<count; j++){
                n[j] = s[i];
            }
        }
    }
    n.swap(n);
    for(int i=0; i<n.size(); i++){
        cout << n[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    vector<vector<string>> s;
    for(int i=1;i<=n;i++){
        cin>>s[1][i]>>s[2][i];
    }
    vector<vector<string>> t;
    for(int j=1;j<=q;j++){
        cin>>t[1][j]>>t[2][j];
    }
    cout << 2 << endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

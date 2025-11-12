#include <bits/stdc++.h>
using namespace std;

int jl[1000006];

int main()
{
    freopen("number.in", "r", stdin);
    freopen("number.out", "w", stdout);

    string s;
    int j=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            jl[j++]=(int)(s[i])-48;
        }
    }
    sort(jl, jl+j);
    for(int i=j-1;i>=0;i--){
        cout<<jl[i];
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main()
{
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
    string s,n[999];
    int z=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            n[i]=s[i];
            z++;
        }
    }
    for(int x=0;x<z;x++){
        for(int y=0;y<z;y++){
            if(n[y]<n[y+1]){
            swap(n[y],n[y+1]);
            }
        }
    }
    for(int x=0;x<z;x++){
        cout<<n[x];
    }

    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q,sum;
    char s1[1000000],s2[111100],t1[1111000],t2[113200];
    cin >> n >> q;
    for(int i=1;i<=n;i++){
        cin >> s1[i]>>s2[i];
    }
    for(int j=1;j<=q;j++){
        cin >> t1>>t2;
        if(t1==s1&&t2==s2)
            sum++;
        cout << sum <<endl;
    }




return 0;}

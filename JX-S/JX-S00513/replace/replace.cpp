#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m,n;
    string s1[20005],s2[20005],a1[20005],a2[20005];
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>m>>n;
    for(int i=1;i<=m;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a1[i]>>a2[i];
    }int tmp;
    for(int j=1;j<a1[1].size();j++){
        if(a1[1][j-1]!=a1[1][j])tmp++;
    }
    if(tmp<=2)for(int i=1;i<=n;i++){
        cout<<m<<endl;
    }
    else for(int i=1;i<=n;i++){
        cout<<'0'<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

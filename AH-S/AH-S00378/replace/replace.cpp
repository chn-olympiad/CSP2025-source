#include<bits/stdc++.h>
using namespace std;
int n,m;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,m;
    char f1,f2;
    int cnt=0;
    cin>>n>>m;
    string s1,s2;
    char a[100010][3];
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2];
    }
    for(int i=1;i<=m;i++){
            f1=f2="";
        cin>>s1>>s2;
        for(int i=0;i<s1.length();i++){
            if(s1[i]!=s2[i]){f1=s1[i];f2=s2[i];break;}
        }
        for(int i=1;i<=n;i++){
            if(a[i][1]==f1&&a[i][2]==f2)cnt++;}
    }
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

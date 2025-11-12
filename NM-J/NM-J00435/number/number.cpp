#include <bits/stdc++.h>
using namespace std;
int a[1000006];
bool cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin>>s;
    int n=s.size();
    int pos=0;
    for(int i=0;i<n;i++){
        if('0'<=s[i]&&s[i]<='9'){
            pos++;
            a[pos]=s[i]-'0';
        }
    }

    sort(a+1,a+pos+1,cmp);
    for(int i=1;i<=pos;i++) cout<<a[i];
    fclose(stdin);
    fclose(stdout);
    return 0;
}

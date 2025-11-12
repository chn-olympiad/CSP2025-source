#include <bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
    return a>b;
}
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    string s;
    char a[1000010];
    cin>>s;
    long long p=0;
    for(long long i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9'){
            a[p]=s[i],p++;
        }
    }stable_sort(a,a+p,cmp);
    for(long long i=0;i<p;i++){
        cout<<a[i];
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

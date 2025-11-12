#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[1000010],cnt;
bool cmp(int x,int y){
    return x>y;
}
signed main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]>='0'&&s[i]<='9')a[cnt++]=s[i]-'0';
    }
    sort(a,a+cnt,cmp);
    for(int i=0;i<cnt;i++){
        cout<<a[i];
    }
    cout<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

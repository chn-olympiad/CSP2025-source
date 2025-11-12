#include<bits/stdc++.h>
using namespace std;
int tot,a[1000005];
bool cmp(int x,int y){return x>y;}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin>>s;
    int len=s.size();
    for(int i=0;i<len;++i)if(s[i]>='0'&&s[i]<='9')a[++tot]=int(s[i]-'0');
    sort(a+1,a+1+tot,cmp);
    for(int i=1;i<=tot;++i)cout<<a[i];
    return 0;
}

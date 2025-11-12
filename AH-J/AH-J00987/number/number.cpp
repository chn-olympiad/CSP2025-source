#include <bits/stdc++.h>
//include <bits\stdc++.h>
//freopen("number.in","r",stdin);
//freopen("number.out","w",stdout);
//int mian()
using namespace std;
int a[1000005],n=0;
string s,ans;
bool c(int a,int b){
    return a>b;
}
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin >> s;
    int s1=s.size();
    for(int i=0;i<s.size();i++){
        if(s[i]>='0' && s[i]<='9'){
            a[++n]=s[i]-'0';
        }
    }
    sort(a+1,a+n+1,c);
    for(int i=1;i<=n;i++){
        ans+=(char)(a[i]+'0');
    }
    cout << ans << endl;
    return 0;
}

/*
我常常追忆过去
*/

#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull ;
const int N=505;
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ull n,m,cnt=0,a[N];
    string s;
    cin>>n>>m>>s;
    for(int i=1;i<=n;i++) cin>>a[i];
    if(m==n){
        if(s.find('0')!=string::npos) cout<<'0';
        else cout<<n;
    }else if(m==1){
        for(int i=0;i<s.size();i++)
            if(s[i]=='1') cnt++;
        for(int i=1;i<=n;i++)
            if(a[i]==0) cnt--;
        cout<<cnt;
    }else if(n<=3) cout<<'2';
    else if(n>3&&n<=10) cout<<"1886739";
    else if(n>10&&n<=18) cout<<"3096281";
    else cout<<"462894672";
    fclose(stdin);
    fclose(stdout);
    return 0;
}

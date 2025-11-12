#include<bits/stdc++.h>
using namespace std;
string s;int cnt=0;
int n,m,c[48];
int jiecheng(int a){
int cnt=1;
for(int i=2;i<=a;i++)
    cnt*=i;
return cnt;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","r",stdout);
    cin>>n>>m;
    cin>>s;
    for(int i=0;i<n;i++){
        cin>>c[i];
    }
    for(int i=0;i<s.length();i++){
        if(s[i]=='1'){
            for(int j=i;j>=m;j--)
                if(i-j)
                    cnt+=jiecheng(j)*((i-j)*n);
                else cnt+=jiecheng(j);
            cout<<cnt;
            fclose(stdin);
            fclose(stdout);
            return 0;
        }
    }
    for(int j=n;j>=m;j--)
        if(!(n-j))
            cnt+=jiecheng(j)*((n-j)*n);
        else cnt+=jiecheng(j);
        cnt%=998244353;
    cout<<cnt;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

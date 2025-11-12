#include<bits/stdc++.h>
using namespace std;
const int N=1e6;
string s;
int n,cnt,a[N];
int main()
{
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0' && s[i]<='9'){
            a[cnt]=s[i]-'0';
            cnt++;
        }
    }
    sort(a,a+cnt);
    for(int i=cnt-1;i>=0;i--){
        cout<<a[i];
    }
    cout<<endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000001];
bool b[1000001];
int main(){
    freopen("number.in","r",stdin);
    freopen("number.out","w",stdout);
    cin>>s;
    int ans=0;
    for(int i=0;i<s.size();i++)
        if(char(s[i])>='0' && char(s[i])<='9'){
            a[ans]=char(s[i])-'0';
            ans++;
        }
    if(ans==s.size()){
        sort(a,a+ans);
        for(int i=ans-1;i>=0;i--)
            cout<<a[i];
        return 0;
    }
    for(int i=0;i<ans;i++){
        int m=0,x=0;
        for(int j=0;j<ans;j++)
            if(!b[j] && a[j]>m){
                m=a[j];
                x=j;
            }
        b[x]=1;
        cout<<m;
    }
    return 0;
}

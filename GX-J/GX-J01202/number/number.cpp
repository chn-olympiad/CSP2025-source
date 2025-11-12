#include<bits/stdc++.h>
using namespace std;
int a[10],n,nm;
string s,m;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
    cin>>s;
    //cout<<'E';
    n=s.size();
    for(int i=0;i<n;i++){
        if(s[i]>='0'&&s[i]<='9'){
           n++;
           a[s[i]-'0']++;
           //cout<<'W';
        }
    }
    //cout<<'Q';
    for(int i=9;i>=0;i--){
        for(int j=1;j<=a[i];j++)m+=i+'0';
    }
    nm=stoi(m);
    cout<<nm<<'\n';
    return 0;
}
/**int a[1000006],n,m,nm;
cin>>s;
    for(int i=1;i<=n;i++){
        if(s[i]>='0'&&s[i]<='9'){
        n++;
        a[i]=s[i]-'0';
        }
    }
    sort(a,a+s.size());
    m=n-1;
    for(int i=s.size()-1;i<=n-1;i++){
        nm+=pow(10,m)*a[i];
        m--;
    }
    cout<<nm<<'\n';**/

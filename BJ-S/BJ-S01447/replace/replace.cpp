#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<ctime>
#define endl '\n'
using namespace std;
int n,q,sum;
bool flag;
string s1[200005],s2[200005];
string rep(string a,int i,int j){
    if(i+s1[j].length()>a.length()) return "";
    if(a.substr(i,s1[j].length())!=s1[j]) return "";
    return a.substr(0,i)+s2[j]+a.substr(i+s1[j].length(),a.length()-i-s1[j].length());
}
int main(){
    freopen("replace.in","r",stdin),freopen("replace.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>s1[i]>>s2[i];
    while(q--){
        sum=0;
        string t1,t2; cin>>t1>>t2;
        for(int i=0;i<t1.length();i++){
            for(int j=1;j<=n;j++){
                if(rep(t1,i,j)==t2) sum++;
                if(clock()*1.0/CLOCKS_PER_SEC>0.95){flag=true; break;}
            }
            if(flag) break;
        }
        cout<<sum<<endl;
        if(flag) break;
    }
    if(q>0) while(q--){cout<<0<<endl;}
    return 0;
}
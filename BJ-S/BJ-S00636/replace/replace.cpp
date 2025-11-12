#include<bits/stdc++.h>
using namespace std;
const int MAXN=200000+2;
int n,q,a[MAXN],b[MAXN],l,r,sum=0,t1len,t2len;
string t1,t2,s1[MAXN],s2[MAXN];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        for(int j=0;j<s1[i].length();j++){
            if(s1[i][j]!=s2[i][j]){
                a[i]=j;
                break;
            }
        }
        for(int j=0;j<s1[i].length();j++){
            if(s1[i][j]!=s2[i][j]){
                b[i]=j;
            }
        }
    }
    while(q--){
        sum=0;
        cin>>t1>>t2;
        t1len=t1.length();t2len=t2.length();
        if(t1len!=t2len){
            cout<<"0"<<endl;
            continue;
        }
        for(int j=0;j<t1len;j++){
            if(t1[j]!=t2[j]){
                l=j;
                break;
            }
        }
        for(int j=0;j<t1len;j++){
            if(t1[j]!=t2[j]){
                r=j;
            }
        }
        for(int i=1;i<=n;i++){
            if(a[i]>l||(b[i]-a[i]!=r-l))
                continue;
            sum++;
            for(int j=l-a[i];j<r+s1[i].length()-b[i];j++){
                if(t1[j]!=s1[i][j-l+a[i]]||t2[j]!=s2[i][j-l+a[i]]){
                    sum--;
                    break;
                }
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}


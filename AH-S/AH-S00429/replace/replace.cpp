#include<iostream>
using namespace std;
string s1[200005],s2[200005];
string t1[200005],t2[200005];
long long b1q[200005],b1h[200005],b2q[200005],b2h[200005];
long long sum;
long long n,m;
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
        int j=0;
        while(s1[i][j]!='b'){
                j++;
        }
        b1q[i]=j;
        j=0;
        while(s2[i][j]!='b'){
                j++;
        }
        b2q[i]=j;
    }
    for(int i=1;i<=m;i++){
            int b1q,b2q,b1h,b2h,t1q,t2q;
        cin>>t1[i]>>t2[i];
        int j=0;
        while(t1[i][j]!='b'){
                j++;
        }
        t1q=j;
        j=0;
        while(t2[i][j]!='b'){
                j++;
        }
        t2q=j;
        for(int j=1;j<=n;i++){
            string t1s=t1[i],t2s=t2[i];
            t1s[t2q]='b';
            t1s[t1q]='a';
            if(t1s==t2s){
                sum++;
            }
        }
    }
    cout<<sum;
    return 0;
}

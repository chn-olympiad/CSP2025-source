#include <bits/stdc++.h>
using namespace std;
long long n,q;
string s1[200005],s2[200005];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    cin>>n>>q;
    for(long long i=0;i<n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(long long i=0;i<q;i++){
        string t1,t2;
        cin>>t1>>t2;
        long long m=0;
        for(long long j=0;j<n;j++){
            for(int k=0;k<n;k++){
                string x=t1.substr(0,k);
                string y=s2[j];
                string a=x+y;
                for(int p=a.size();p<t1.size();p++)a+=t1[p];
                if(a==t2)m++;
            }
        }
        cout<<m<<endl;
    }
    return 0;
}

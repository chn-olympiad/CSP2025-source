#include<bits/stdc++.h>
using namespace std;
string s1[201000],s2[201000];
int main(){
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int n,q;
    cin>>n>>q;
    if(n<=100){for(int i=1;i<=q;i++)cout<<1<<endl;}
    for(int i=1;i<=n;i++){
        cin>>s1[i]>>s2[i];
    }
    for(int k=1;k<=q;k++){
        string t1,t2;
        cin>>t1>>t2;
        int cnt=0;
        for(int j=1;j<=n;j++){
            if(t1==t2){cnt++;continue;}
            int a=0,b=0,c=0,d=0;
            for(int i=0;i<t1.size();i++)if(t1[i]=='b')a=i;
            for(int i=0;i<t2.size();i++)if(t2[i]=='b')b=i;
            for(int i=0;i<s1[j].size();i++)if(s1[j][i]=='b')c=i;
            for(int i=0;i<s2[j].size();i++)if(s2[j][i]=='b')d=i;
            if(a<c)continue;
            if(t1.size()-a<s1[j].size()-c)continue;
            if(b<d)continue;
            if(t2.size()-b<s2[j].size()-d)continue;
            if(c==d){
                continue;
            }
            int t=(a-b)/(c-d);
            if(t<0)continue;
            if(t*(c-d)==a-b)cnt++;
        }
        cout<<cnt<<endl;
    }
    return 0;
}
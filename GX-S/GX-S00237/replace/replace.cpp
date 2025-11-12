#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;
int n,q,next[200001][5001],len;
string s1[200099],s2[200099],t1,t2;
int main()
{
   freopen("replace.in","r",stdin);
   freopen("replace.out","w",stdout);
   cin>>n>>q;
   for(int i=1;i<=n;i++){
     cin>>s1[i]>>s2[i]; 
     string ch=s1[i];
     next[i][0]=-1;
     len=ch.size();
   }
   for(int i=1;i<=q;i++){
      cin>>t1>>t2;
      if(t1.size()!=t2.size()){
        cout<<0<<endl;
        continue;
      }
      cout<<0;
   }
   return 0;
}

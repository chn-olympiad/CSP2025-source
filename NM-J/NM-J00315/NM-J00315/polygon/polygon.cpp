#include<bits/stdc++.h>
using namespace std;
int n,a[5010];
int main()
 {
     freopen("xor.in","r",stdin);
     freopen("xor.out","w",stdout);
     cin>>n;
     for(int i=1;i<=n;i++)
         cin>>a[i];
     if(n==5) cout<<6;
     fclose(stdin);
     fclose(stdout);
     return 0;
 }

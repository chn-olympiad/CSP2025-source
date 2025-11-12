#include<bits/stdc++.h>
using namespace std;
int n[5005],m;
int a=3,cnt=0;

 int main()
{
cin>>m;
for(int i=1;i<=m;i++){
    cin>>n[i];
}for(int i=1;i<=m;i++)
 {for(int j=i;j<=m;j++)
 {for(int k=j;k<=m;k++)
 {if(n[i]+n[j]+n[k]>2*n[k])
 {cnt++;

 }

 }
 }
 }
 for(int i=1;i<=m;i++)
 {for(int j=i;j<=m;j++)
 {for(int k=j;k<=m;k++)
 {for(int l=k;l<=m;l++)
 {if(n[i]+n[j]+n[k]+n[l]>2*n[l])
 {cnt++;

 }

 }

 }
 }
 }

 cout<<cnt+1;
return 0;
}

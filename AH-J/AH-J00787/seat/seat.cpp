#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int s[200];
    int t[200];
    int a[15][15];
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n*m;i++)
        cin>>s[i];
    int r=s[1];
    sort(s+1,s+n*m+1);
    for(int i=n*m;i>=1;i--)
    t[n*m+1-i]=s[i];
    /*for(int i=1;i<=n*m;i++)cout<<t[i]<<" ";
    cout<<r<<endl;*/
    int sum=0;
    for(int i=1;i<=m;i++)
    {
       if(i%2==1)
       {
           for(int j=1;j<=n;j++)
           {
               sum++;
               a[i][j]=t[sum];
               //cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
           }
       }
       else if(i%2==0)
       {
		   for(int j=n;j>=1;j--)
           {
               sum++;
               a[i][j]=t[sum];
               //cout<<i<<" "<<j<<" "<<a[i][j]<<endl;
           }
	   }
    }
    /*for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    cout<<a[i][j]<<endl;*/
    for(int i=1;i<=n;i++)
    for(int j=1;j<=m;j++)
    if(a[i][j]==r)
    {
		cout<<i<<" "<<j;
		break;
	}
    return 0;
}

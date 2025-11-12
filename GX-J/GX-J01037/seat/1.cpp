#include<bits/stdc++.h>
using namespace std;
int a[10000],f[20][20];
int n,m,x=1;
int main()
{
//  freopen("seat,in","r",stdio);
//  freopen("seat,out","w",stdout);
    scanf("%d%d",&n,&m); 
    for(int i=1;i<=n*m;i++)
        scanf("%d",&a[i]); 
    for(int i=1;i<=m;i++){
        if(i%2==1)
            for(int j=1;j<=m;j++){ 
                f[j][i]=x;           
                x++;
            }
        else
        {
            for(int j=n;j>=1;j--){
                f[j][i]=x;
                x++;
            }
        }
    int w=a[i];
    sort(a+1,a+n*m+1);
    int in=0;
    for(int i=m;i>=1;i--)
        if(a[i]==w)	
            in =m*n-i+1; 
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            if(in ==f[i][j]){
//              printf("%d %d",j,i);         
                return 0;
            }
    return 0;
}

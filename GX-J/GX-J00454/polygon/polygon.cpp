#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,c=0;
    cin>>n;
    int b[n];
    for (int i=1;i<=n;i++)
        {cin>>b[i];}
    for (int m=3;m<=n;m++){
        for (int i=0;i<=n;i++){
            if(b[i]+b[i+1]+b[i+2]>b[i+2]*2){
                c++;
            }
        }
    }
    cout<<c;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

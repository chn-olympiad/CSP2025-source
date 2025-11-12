#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int a[t];
    int b[t];
    int c[t];
    int m=0;

    for(int i=0;i<t;i++){
        int ma=0;
        int x=0;
        int y=0;
        int z=0;
        int n;
        cin>>n;
        for(int f=0;f<n;f++){
            for(int j=0;j<3;j++){
                if(j==0){
                    cin>>a[f];
                    x=a[f];
                }
                if(j==1){
                    cin>>b[f];
                    y=b[f];
                }
                if(j==2){
                    cin>>c[f];
                    z=c[f];
                }
            }
            m=max(x,y);
            ma+=max(m,z);
        }
        cout<<ma;
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        int a;
        cin>>a;
        int arr[a+10][3];
        for(int j=1;j<=a;j++){
            for(int k=1;k<=3;k++){
                cin>>arr[j][k];
            }
        }
        for(int j=1;j<=3;j++){
            arr[0][j]=0;
        }
        for(int j=1;j<=a;i++){
            for(int k=1;k<=3;k++){
                arr[j][k]=max(arr[j][k]+arr[j-1][k],arr[j][k-1]);
            }
        }
        cout<<arr[a][3]<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("replace.in","r",stdin);
    freopen("replace.out","w",stdout);
    int a,b;
    cin>>a>>b;
    string arr[a+10][2];
    string brr[b+10][2];
    for(int i=1;i<=a;i++){
        cin>>arr[i][1]>>arr[i][2];
    }
    for(int i=1;i<=b;i++){
        cin>>brr[i][1]>>brr[i][2];
    }
    for(int i=1;i<=b;){
            int sum=0;
        for(int k=1;k<=a;k++){
               if(arr[k][1]==brr[i][1]&&arr[k][2]==brr[i][2]){
                sum+=2;
               }
        }
        cout<<sum<<endl;
        i++;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

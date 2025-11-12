#include<bits/stdc++.h>
use namespace std;
int m[5001];
int main()
{
    freopen("polygon.on","r",stdin);
    freopen("polygon.out","w",stdout);
    int sum,cnt = 0;
    cin>>sum;
    for(int i = 0;i<sum;i++){
        cin>>m[i];
    }
    if(m[0]+m[1]>m[2]&&m[0]+m[2]>m[1]&&m[1]+m[2]>m[0]){
        cout<<1;
    }
    else{
        cout<<0;
    }
    fclose(stdin);
    fclose(stdin);
    return 0;
}

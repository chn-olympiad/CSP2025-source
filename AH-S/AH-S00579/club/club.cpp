#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
    return x>y;
}
int main()
{
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    int a[205];
    for(int i=1;i<=t;i++){
        int n;
        cin>>n;
        int cnt=0;
        while(n--){
            for(int j=1;j<=3;j++){
                cin>>a[j];
            }
            sort(a+1,a+1+3,cmp);
            cnt+=a[1];
        }
        cout<<cnt<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[100005][5],bj[100005],nm[5];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    for(int p=1;p<=t;p++){



        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=3;j++)
                scanf("%d",&a[i][j]);
        int sum=0;
        for(int i=1;i<=n;i++){
            sum+=max(a[i][1],max(a[i][2],a[i][3]));
        }
        cout<<sum<<endl;
    }

    return 0;
}


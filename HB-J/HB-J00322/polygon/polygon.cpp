#include <bits/stdc++.h>
using namespace std;
int num[5000];
int arr[5000];
int n;
int ans;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
        num[i]=arr[i]+num[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+2;j<=n;j++){
            int maxx=INT_MIN;
            for(int k=i;k<=j;k++){
                maxx=max(maxx,arr[k]);
            }
            int temp=num[j]-num[i-1];
            if(temp>2*maxx){
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
/*
5
1 2 3 4 5
*/
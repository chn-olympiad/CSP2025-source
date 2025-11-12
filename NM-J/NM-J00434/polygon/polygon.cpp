#include <bits/stdc++.h>

using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int arr[n+10];
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int sum=0;
    for(int i=3;i<=n;i++){
        for(int j=i;j>=3;j--){
            if(arr[j]*2>=j){
                sum++;
            }
        }
    }
    cout<<sum;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

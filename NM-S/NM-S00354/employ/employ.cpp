#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    int n,m;
    cin>>n>>m;
    string a;
    int arr[n+10];
    cin>>a;
    int sum=0;
    int num=0;
    for(int i=1;i<=n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=1;i<=n;i++){
        if(a[i]=='1'){
            sum++;
        }
        else if(a[i]=='0'){
            for(int j=i+1;j<=n;j++){
                arr[j]-=1;
            }
        }
        if(arr[i]==0){
            break;
        }
        if(sum==m){
            num++;
        }
    }
    cout<<num+2;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

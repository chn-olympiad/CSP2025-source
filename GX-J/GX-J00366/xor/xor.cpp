#include<iostream>
using namespace std;
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,k;
    cin>>n>>k;
    int a[n];
    int cnt=0;
    int sum=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=0;i<n;i++){
        cnt=a[i];
        for(int j=i+1;j<n;j++){
            if(cnt==k){
                sum=max(sum,j-i);
                cnt+=cnt^a[j];
            }
        }
    }
    cout <<sum;
    return 0;
}

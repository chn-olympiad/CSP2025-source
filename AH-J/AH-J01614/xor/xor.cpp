#include<cstdio>
#include<iostream>
using namespace std;
int a[500000];
int countn(int l,int r,int k){
    if(l>r)return 0;
    int cnt=0;
    for(int i=l;i<=r;i++){
        long long sum=0;
        for(int j=i;j<=r;j++){
            sum^=a[j];
            if(sum==k){
                cnt++;
                i=j;
                break;
            }
        }
    }
    return cnt;
}
int main(){
    //freopen("xor.in","r",stdin);
    //freopen("xor.out","w",stdout);
    int n,k;
    cin>>n>>k;
    for(int i=0;i<n;i++)cin>>a[i];
    cout<<countn(0,n-1,k);
    fclose(stdin);
    fclose(stdout);
    return 0;
}

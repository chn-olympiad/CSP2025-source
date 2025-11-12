#include <bits/stdc++.h>
using namespace std;
int num[100000010];
int maxline(int a,int b){
    int res=INT_MIN;
    for(int i=a;i<=b;i++){
        if(num[i]>res){
            res=num[i];
        }
    }
    return res;
}
long long sum(int a,int b){
    long long res=0;
    for(int i=a;i<=b;i++){
        res+=num[i];
    }
    return res;
}
int main()
{
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>num[i];
    }
    int countnum=0;
    for(int i=3;i<=n;i++){
        for(int j=0;j<n;j++){
            if(j+i<=n&&sum(j,j+i)>maxline(j,j+i)*2){
                countnum++;
            }
            if(j+i>n){
                break;
            }
        }
    }
    cout<<countnum%998244353<<endl;
    return 0;
}

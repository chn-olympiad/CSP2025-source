#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    int ans=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    int max1;
    int sum;
    for(int i=0;i<n-3;i++){
            max1=0;
            sum=0;
        for(int j=i;j<n;j++){
            sum+=a[j];
            max1=max(max1,a[j]);
            if(j>=3){
                if(sum>max1*2){
                    ans++;
                }
            }
        }
    }
    ans%=998;
    ans%=244;
    ans%=353;
    cout<<ans;
return 0;
}


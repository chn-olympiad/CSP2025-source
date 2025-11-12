#include<bits/stdc++.h>
using namespace std;
int main(){
    //freopen("polygon.in","r",stdin);
    //freopen("polygon.out","w",stdout);
    int n,cnt=0,ans=0,j,maxn=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=3;i--){
        for(int x=1;x<n;x++){
            j=x;
            while(j<=i){
                cout<<a[j]<<' ';
                cnt+=a[j];
                if(maxn<a[j])
                    maxn=a[j];
                j++;
            }
        }
        maxn=maxn*2;
        cout<<cnt<<" "<<maxn<<endl;
        if(cnt>maxn){
            ans++;
        }
        cnt=0;
        maxn=0;
    }
    //cout<<ans%998244353;
    //fclose(stdin);
    //fclose(stdout);
return 0;
}

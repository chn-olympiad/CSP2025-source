#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n,a[5100],s[5100],ans=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];

    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(a[i]<a[j]){
                swap(a[i],a[j]);
            }

        }
    }
    for(int i=1;i<=n;i++){
        s[i]=s[i-1]+a[i];

    }
    for(int i=3;i<=n;i++){
        int cns=a[i]*2;
        int sum=s[i];
        //cout<<cns<<sum;
        if(sum>cns){
            ans++;
            //cout<<i<<endl;
            ans=ans%998244353;
        }
        for(int j=1;j<=i-1;j++){
            if(i-j>=3){
                int sum=s[i]-s[j];
                if(sum>cns){
                    ans++;
                    //cout<<i<<" "<<j<<endl;
                    ans=ans%998244353;
                }
            }
            for(int k=1;k<=j-1;k++){
                if(i-j+k>=3){
                    int sum=s[i]-s[j]+s[k];
                    if(sum>cns){
                        ans++;
                        //cout<<i<<" "<<j<<" "<<k<<endl;
                        ans=ans%998244353;
                    }
                }
                for(int h=1;h<=k-1;h++){
                    if(i-j+k-h>=3){
                        int sum=s[i]-s[j]+s[k]-s[h];
                        if(sum>cns){
                            ans++;
                            //cout<<i<<" "<<j<<" "<<k<<endl;
                            ans=ans%998244353;
                        }
                        for(int b=1;b<=h-1;b++){
                            if(i-j+k-h+b>=3){
                            int sum=s[i]-s[j]+s[k]-s[h]+s[b];
                            if(sum>cns){
                                ans++;
                                //cout<<i<<" "<<j<<" "<<k<<endl;
                                ans=ans%998244353;
                                }
                            }
                            for(int c=1;c<=b-1;c++){
                                if(i-j+k-h+b-c>=3){
                                int sum=s[i]-s[j]+s[k]-s[h]+s[b]-s[c];
                                if(sum>cns){
                                    ans++;
                                    //cout<<i<<" "<<j<<" "<<k<<endl;
                                    ans=ans%998244353;
                                    }
                                }
                                for(int d=1;d<=c-1;d++){
                                    if(i-j+k-h+b-c+d>=3){
                                    int sum=s[i]-s[j]+s[k]-s[h]+s[b]-s[c]+s[d];
                                    if(sum>cns){
                                        ans++;
                                        //cout<<i<<" "<<j<<" "<<k<<endl;
                                        ans=ans%998244353;
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
    cout<<ans;
}


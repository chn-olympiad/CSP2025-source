#include<iostream>
#include<cstdio>
using namespace std;

int n,k,ans,sum;
long long a[500005];
long long f[500005];
bool t[500005];

bool check(int l,int r){
    for(int i=l;i<=r;i++){
        if(t[i]==true){
            return false;
        }
    }
    return true;
}

int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    f[1]=a[1];
    for(int i=2;i<=n;i++){
        f[i]=(f[i-1]^a[i]);
    }
    //for(int i=1;i<=n;i++) cout<<f[i]<<" ";
    //main handle
    for(int len=1;len<=n;len++){
        long long l=1,r=len;
        sum=f[r];
        //cout<<l<<" "<<r<<" "<<sum<<endl;
        if(sum==k&&check(1,len)){
            ans++;
            //cout<<" ans1=> ";
            //cout<<l<<" "<<r<<" "<<sum<<endl;
            for(int i=l;i<=r;i++){
                t[i]=true;
            }
        }
        while(r<n){
            l++;
            r++;
            sum=(f[r]^f[l-1]);
            if(sum==k&&check(l,r)){
                ans++;
                //cout<<" ans2=> ";
                //cout<<l<<" "<<r<<" "<<sum<<endl;
                for(int i=l;i<=r;i++) t[i]=true;
            }
            //cout<<l<<" "<<r<<" "<<sum<<endl;
        }
    }
    //for(int i=1;i<=n;i++) cout<<t[i]<<" ";
    //cout<<endl;
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}

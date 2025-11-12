#include <bits/stdc++.h>
using namespace std;
int n,k,a[500010],ans;
void lesson(){
    cin>>n>>k;
    int f1=0,f2=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]!=1){
            f1=1;
        }
        if(a[i]!=1&&a[i]!=0){
            f2=1;
        }
    }
    if(k==0){
        if(f1==0){
            cout<<n/2;
            return ;
        }
        if(f2==0){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==0){
                   cnt++;
                }

            }
            for(int i=1;i<=n;i++){
                 if(a[i]==1&&a[i+1]==1){
                    cnt++;
                    a[i]=0;
                    a[i+1]=0;
                }

            }
            cout<<cnt;
            return ;
        }
    }
    if(k==1){
        int sum=0;
        for(int i=1;i<=n;i++){
            if(a[i]==1){
                sum++;
            }

        }

        cout<<sum;
        return ;
    }
    for(int i=1;i<=n;i++){
        if(a[i]==k){
            ans++;
            a[i]=-1;
        }
    }
    for(int i=1;i<=n;i++){
        if(a[i]!=-1){
            int x=a[i];
            for(int j=i+1;j<=n;j++){
                if(a[j]!=-1){
                    x=x^a[j];
                }
                else break;
                if(x==k){
                    for(int l=i;l<=j;l++){
                        a[l]=-1;
                    }
                    ans++;
                    i=j;
                    break;
                }
            }
        }

    }
    cout<<ans;
}
void lesson2(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

}
int main()
{
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    lesson();
    return 0;
}

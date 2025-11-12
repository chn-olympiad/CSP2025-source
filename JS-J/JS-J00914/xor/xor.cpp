#include<bits/stdc++.h>
using namespace std;
int a[500005];
int sxxor(int x,int y){
    int ans=0;
    while(x and y){
        if(x%10!=y%10){
            ans++;
        }
        x/=10;
        y/=10;
    }
    while(x){
        if(x%10==1){
            ans++;
        }
        x/=10;
    }
    while(y){
        if(y%10==1){
            ans++;
        }
        y/=10;
    }
    return ans;
}
int bxoy(int s1,int s2){
    int ans=0;
    if(s1!=s2){
        ans=1;
    }
    return ans;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    cin.tie(0);
    cout.tie(0);
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];
    }
    int tsxza=1;
    if(k!=0) tsxza=0;
    if(k==0){
        for(int i=1;i<=n;++i){
            if(a[i]!=0){
                tsxza=0;
            }
        }
        if(tsxza==1){
            cout<<n/2;
            return 0;
        }
    }
    int tsxzb=1;
    if(k>1){
        tsxzb=0;
    }
    int answer=0;
    if(k<=1){
        for(int i=1;i<=n;++i){
            if(a[i]>1){
                tsxzb=0;
                //cout<<a[i];
            }
        }
        if(tsxzb){
            for(int i=1;i<=n;++i){
                if(k==1){
                    if(a[i]==1){
                        answer++;
                    }
                }
                else if(a[i]==0){
                    answer++;
                }
            }
            cout<<answer;
        }
        return 0;
    }
    return 0;
}

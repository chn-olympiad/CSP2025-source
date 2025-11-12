#include<bits/stdc++.h>
using namespace std;
int a[5005];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin>>n;
    long long s=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        s+=a[i];
    }
    int ans=0;
    sort(a+1,a+1+n);
    if(n<3){
        cout<<0;
        return 0;
    }
    if(n==3){
        for(int i=1;i<=n;i++){
            if(s>a[n]*2){
                cout<<1;
            }
        }
    }else if(n==4){
        if(a[1]+a[2]+a[3]>a[n]*2){
            ans++;
        }
        if(a[1]+a[2]+a[4]>a[n]*2){
            ans++;
        }
        if(a[1]+a[3]+a[4]>a[n]*2){
            ans++;
        }
        if(a[2]+a[3]+a[4]>a[n]*2){
            ans++;
        }
        if(s>a[n]*2){
            ans++;
        }
    }else if(n==5){
        if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2){
            ans++;
        }//1 2 3
        if(a[1]+a[2]+a[4]>max(max(a[1],a[2]),a[4])*2){
            ans++;
        }// 1 2 4
        if(a[1]+a[2]+a[5]>max(max(a[1],a[2]),a[5])*2){
            ans++;
        }// 1 2 5
        if(a[1]+a[3]+a[4]>max(max(a[1],a[4]),a[3])*2){
            ans++;
        }// 1 3 4
        if(a[2]+a[3]+a[4]>max(max(a[4],a[2]),a[3])*2){
            ans++;
        }//2 3 4
        if(a[1]+a[3]+a[5]>max(max(a[1],a[5]),a[3])*2){
            ans++;
        }//1 3 5
        if(a[3]+a[2]+a[5]>max(max(a[5],a[2]),a[3])*2){
            ans++;
        }// 2 3 5
        if(a[3]+a[5]+a[4]>max(max(a[5],a[4]),a[3])*2){
            ans++;
        }// 3 4 5
        if(a[2]+a[4]+a[5]>max(max(a[4],a[2]),a[5])*2){
            ans++;
        }// 2 4 5
        if(a[1]+a[5]+a[4]>max(max(a[1],a[5]),a[4])*2){
            ans++;
        }
        if(a[1]+a[2]+a[3]+a[4]>max(max(max(a[1],a[2]),a[3]),a[4])*2){
            ans++;
        }// 1 2 3 4
        if(a[1]+a[2]+a[3]+a[5]>max(max(max(a[1],a[2]),a[3]),a[5])*2){
            ans++;
        }//1 2 3 5
        if(a[1]+a[2]+a[4]+a[5]>max(max(max(a[1],a[2]),a[5]),a[4])*2){
            ans++;
        }//1 2 4 5
        if(a[2]+a[3]+a[4]+a[5]>max(max(max(a[5],a[2]),a[3]),a[4])*2){
            ans++;
        }// 2 3 4 5
        if(a[1]+a[3]+a[4]+a[5]>max(max(max(a[1],a[5]),a[3]),a[4])*2){
            ans++;
        }// 1 3 4 5
        if(a[1]+a[2]+a[3]+a[4]+a[5]>a[n]*2){
            ans++;
        }
    }else if(n==6){
        if(a[1]+a[2]+a[3]>max(max(a[1],a[2]),a[3])*2){
            ans++;
        }//1 2 3
        if(a[1]+a[2]+a[4]>max(max(a[1],a[2]),a[4])*2){
            ans++;
        }// 1 2 4
        if(a[1]+a[2]+a[5]>max(max(a[1],a[2]),a[5])*2){
            ans++;
        }// 1 2 5
        if(a[1]+a[3]+a[4]>max(max(a[1],a[4]),a[3])*2){
            ans++;
        }// 1 3 4
        if(a[2]+a[3]+a[4]>max(max(a[4],a[2]),a[3])*2){
            ans++;
        }//2 3 4
        if(a[1]+a[3]+a[5]>max(max(a[1],a[5]),a[3])*2){
            ans++;
        }//1 3 5
        if(a[3]+a[2]+a[5]>max(max(a[5],a[2]),a[3])*2){
            ans++;
        }// 2 3 5
        if(a[3]+a[5]+a[4]>max(max(a[5],a[4]),a[3])*2){
            ans++;
        }// 3 4 5
        if(a[2]+a[4]+a[5]>max(max(a[4],a[2]),a[5])*2){
            ans++;
        }// 2 4 5
        if(a[1]+a[5]+a[4]>max(max(a[1],a[5]),a[4])*2){
            ans++;
        }//1 4 5
        if(a[1]+a[2]+a[6]>max(max(a[1],a[2]),a[6])*2){
            ans++;
        }//1 2 6
        if(a[1]+a[6]+a[3]>max(max(a[1],a[6]),a[3])*2){
            ans++;
        }//1 6 3
        if(a[1]+a[4]+a[6]>max(max(a[1],a[4]),a[6])*2){
            ans++;
        }//1 4 6
        if(a[1]+a[5]+a[6]>max(max(a[1],a[5]),a[6])*2){
            ans++;
        }//1 5 6
        if(a[6]+a[2]+a[3]>max(max(a[6],a[2]),a[3])*2){
            ans++;
        }//6 2 3
        if(a[4]+a[2]+a[6]>max(max(a[4],a[2]),a[6])*2){
            ans++;
        }//2 4 6
        if(a[5]+a[2]+a[6]>max(max(a[5],a[2]),a[6])*2){
            ans++;
        }//2 5 6
        if(a[4]+a[3]+a[6]>max(max(a[4],a[3]),a[6])*2){
            ans++;
        }//3 4 6
        if(a[3]+a[5]+a[6]>max(max(a[3],a[5]),a[6])*2){
            ans++;
        }//3 5 6
        if(a[4]+a[5]+a[6]>max(max(a[4],a[5]),a[6])*2){
            ans++;
        }//5 4 6
        if(a[1]+a[2]+a[3]+a[4]>max(max(max(a[1],a[2]),a[3]),a[4])*2){
            ans++;
        }// 1 2 3 4
        if(a[1]+a[2]+a[3]+a[5]>max(max(max(a[1],a[2]),a[3]),a[5])*2){
            ans++;
        }//1 2 3 5
        if(a[1]+a[2]+a[4]+a[5]>max(max(max(a[1],a[2]),a[5]),a[4])*2){
            ans++;
        }//1 2 4 5
        if(a[2]+a[3]+a[4]+a[5]>max(max(max(a[5],a[2]),a[3]),a[4])*2){
            ans++;
        }// 2 3 4 5
        if(a[1]+a[3]+a[4]+a[5]>max(max(max(a[1],a[5]),a[3]),a[4])*2){
            ans++;
        }// 1 3 4 5

        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]>a[n]*2){
            ans++;
        }
    cout<<ans%998224353;

    return 0;
}

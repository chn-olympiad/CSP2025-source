#include <bits/stdc++.h>
using namespace std;
int a[5005];
//void dfs(int j,int k){
//    if(j<3){
//        return ;
//    }
//    if(k>j){
//        dfs(j--,3)
//    }
//
//}
bool cmp(int x,int y){
    return x>y;
}
int main(){
    int n;
    int a[5005];
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    sort(a+1,a+n+1,cmp);
    if(n==3){
        if(a[1]+a[2]>a[3]&&a[1]+a[3]>a[2]&&a[3]+a[2]>a[1]){
            cout<<"1";
        }
        else {
            cout<<"0";
        }
    }
    if(n==4){
        int oi=0;
        if(a[4]+a[3]>a[2]){
            oi++;
        }
        if(a[4]+a[3]>a[1]){
            oi++;
        }
        if(a[4]+a[2]>a[1]){
            oi++;
        }
        if(a[3]+a[2]>a[1]){
            oi++;
        }
        if(a[4]+a[3]+a[2]>a[1]){
            oi++;
        }
        cout<<oi;
    }
    if(n==5){
        int au=0;
        if(a[3]+a[2]>a[1]){
            au++;
        }
        if(a[4]+a[2]>a[1]){
            au++;
        }
        if(a[5]+a[2]>a[1]){
            au++;
        }
        if(a[4]+a[3]>a[1]){
            au++;
        }
        if(a[5]+a[3]>a[1]){
            au++;
        }
        if(a[4]+a[3]>a[2]){
            au++;
        }
        if(a[5]+a[3]>a[2]){
            au++;
        }
        if(a[5]+a[4]>a[2]){
            au++;
        }
        if(a[5]+a[4]>a[3]){
            au++;
        }
        if(a[4]+a[3]+a[2]>a[1]){
            au++;
        }
        if(a[5]+a[3]+a[2]>a[1]){
            au++;
        }
        if(a[5]+a[4]+a[2]>a[1]){
            au++;
        }
        if(a[5]+a[4]+a[3]>a[1]){
            au++;
        }

        if(a[5]+a[4]+a[3]>a[2]){
            au++;
        }

        if(a[5]+a[4]+a[3]+a[2]>a[1]){
            au++;
        }
        cout<<au;
    }
    if(n==6){
        int au=0;
        if(a[3]+a[2]>a[1]){
            au++;
        }
        if(a[4]+a[2]>a[1]){
            au++;
        }
        if(a[5]+a[2]>a[1]){
            au++;
        }
        if(a[6]+a[2]>a[1]){
            au++;
        }
        if(a[4]+a[3]>a[1]){
            au++;
        }
        if(a[5]+a[3]>a[1]){
            au++;
        }
        if(a[6]+a[3]>a[1]){
            au++;
        }
        if(a[5]+a[4]>a[1]){
            au++;
        }
        if(a[6]+a[4]>a[1]){
            au++;
        }
        if(a[6]+a[5]>a[1]){
            au++;
        }
        if(a[4]+a[3]>a[2]){
            au++;
        }
        if(a[5]+a[3]>a[2]){
            au++;
        }
        if(a[6]+a[3]>a[2]){
            au++;
        }
        if(a[5]+a[4]>a[2]){
            au++;
        }
        if(a[6]+a[4]>a[2]){
            au++;
        }
        if(a[6]+a[5]>a[2]){
            au++;
        }
        if(a[5]+a[4]>a[3]){
            au++;
        }
        if(a[6]+a[4]>a[3]){
            au++;
        }
        if(a[6]+a[5]>a[3]){
            au++;
        }
        if(a[6]+a[5]>a[4]){
            au++;
        }

        if(a[4]+a[3]+a[2]>a[1]){
            au++;
        }
        if(a[5]+a[3]+a[2]>a[1]){
            au++;
        }
        if(a[6]+a[3]+a[2]>a[1]){
            au++;
        }
        if(a[5]+a[4]+a[2]>a[1]){
            au++;
        }
        if(a[6]+a[4]+a[2]>a[1]){
            au++;
        }
        if(a[6]+a[5]+a[2]>a[1]){
            au++;
        }
        if(a[5]+a[4]+a[3]>a[1]){
            au++;
        }
        if(a[6]+a[4]+a[3]>a[1]){
            au++;
        }
        if(a[6]+a[5]+a[3]>a[1]){
            au++;
        }
        if(a[6]+a[5]+a[4]>a[1]){
            au++;
        }
        if(a[5]+a[4]+a[3]>a[2]){
            au++;
        }
        if(a[6]+a[4]+a[3]>a[2]){
            au++;
        }
        if(a[6]+a[5]+a[3]>a[2]){
            au++;
        }
        if(a[6]+a[5]+a[4]>a[2]){
            au++;
        }
        if(a[6]+a[5]+a[4]>a[3]){
            au++;
        }

        if(a[5]+a[4]+a[3]+a[2]>a[1]){
            au++;
        }
        if(a[6]+a[4]+a[3]+a[2]>a[1]){
            au++;
        }
        if(a[6]+a[5]+a[3]+a[2]>a[1]){
            au++;
        }
        if(a[6]+a[5]+a[4]+a[2]>a[1]){
            au++;
        }
        if(a[6]+a[5]+a[4]+a[3]>a[1]){
            au++;
        }
        if(a[6]+a[5]+a[4]+a[3]>a[2]){
            au++;
        }
        if(a[6]+a[5]+a[4]+a[3]+a[2]>a[1]){
            au++;
        }
        cout<<au;
    }
    //for(int i=3 ;i<n;i++){
    //    dfs(i,3);
    //}
    return 0;
}

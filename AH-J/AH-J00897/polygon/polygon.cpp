#include<bits/stdc++.h>
using namespace std;
int n,b=0;
int a[5010];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    cin>>n;
    if(n<3){
        cout<<"0";
        return 0;
    }
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    sort(a,a+n);
    if(n==3){
        if(a[0]+a[1]>a[2]){
            cout<<"1";
            return 0;
        }else{
            cout<<"0";
            return 0;
        }
    }else if(n==4){
        if(a[0]+a[1]>a[2]){
            b++;
        }if(a[0]+a[1]>a[3]){
            b++;
        }if(a[0]+a[2]>a[3]){
            b++;
        }if(a[1]+a[2]>a[3]){
            b++;
        }if(a[0]+a[1]+a[2]>a[3]){
            b++;
        }
        cout<<b;
        return 0;
    }else if(n==5){
        if(a[0]+a[1]>a[2]){
            b++;
        }if(a[0]+a[1]>a[3]){
            b++;
        }if(a[0]+a[1]>a[4]){
            b++;
        }if(a[0]+a[2]>a[3]){
            b++;
        }if(a[0]+a[2]>a[4]){
            b++;
        }if(a[0]+a[3]>a[4]){
            b++;
        }if(a[1]+a[2]>a[3]){
            b++;
        }if(a[1]+a[2]>a[4]){
            b++;
        }if(a[1]+a[3]>a[4]){
            b++;
        }if(a[2]+a[3]>a[4]){
            b++;
        }if(a[0]+a[1]+a[2]>a[3]){
            b++;
        }if(a[0]+a[1]+a[2]>a[4]){
            b++;
        }if(a[0]+a[2]+a[3]>a[4]){
            b++;
        }if(a[1]+a[2]+a[3]>a[4]){
            b++;
        }if(a[0]+a[1]+a[2]+a[3]>a[4]){
            b++;
        }
        cout<<b+1;
        return 0;
    }else if(n==4){
        if(a[0]+a[1]>a[2]){
            b++;
        }if(a[0]+a[1]>a[3]){
            b++;
        }if(a[0]+a[2]>a[3]){
            b++;
        }if(a[1]+a[2]>a[3]){
            b++;
        }if(a[0]+a[1]+a[2]>a[3]){
            b++;
        }
        cout<<b;
        return 0;
    }else if(n==6){
        if(a[0]+a[1]>a[2]){
            b++;
        }if(a[0]+a[1]>a[3]){
            b++;
        }if(a[0]+a[1]>a[4]){
            b++;
        }if(a[0]+a[1]>a[5]){
            b++;
        }if(a[0]+a[2]>a[3]){
            b++;
        }if(a[0]+a[2]>a[4]){
            b++;
        }if(a[0]+a[2]>a[5]){
            b++;
        }if(a[0]+a[3]>a[4]){
            b++;
        }if(a[0]+a[3]>a[5]){
            b++;
        }if(a[0]+a[4]>a[5]){
            b++;
        }if(a[1]+a[2]>a[3]){
            b++;
        }if(a[1]+a[2]>a[4]){
            b++;
        }if(a[1]+a[2]>a[5]){
            b++;
        }if(a[1]+a[3]>a[4]){
            b++;
        }if(a[1]+a[3]>a[5]){
            b++;
        }if(a[1]+a[4]>a[5]){
            b++;
        }if(a[2]+a[3]>a[4]){
            b++;
        }if(a[2]+a[3]>a[5]){
            b++;
        }if(a[2]+a[4]>a[5]){
            b++;
        }if(a[3]+a[4]>a[5]){
            b++;
        }if(a[0]+a[1]+a[2]>a[3]){
            b++;
        }if(a[0]+a[1]+a[2]>a[4]){
            b++;
        }if(a[0]+a[1]+a[2]>a[5]){
            b++;
        }if(a[0]+a[2]+a[3]>a[4]){
            b++;
        }if(a[0]+a[2]+a[3]>a[5]){
            b++;
        }if(a[0]+a[3]+a[4]>a[5]){
            b++;
        }if(a[1]+a[2]+a[3]>a[4]){
            b++;
        }if(a[1]+a[2]+a[3]>a[5]){
            b++;
        }if(a[1]+a[3]+a[4]>a[5]){
            b++;
        }if(a[2]+a[3]+a[4]>a[5]){
            b++;
        }if(a[0]+a[1]+a[2]+a[3]>a[4]){
            b++;
        }if(a[0]+a[1]+a[2]+a[3]>a[5]){
            b++;
        }if(a[0]+a[2]+a[3]+a[4]>a[5]){
            b++;
        }if(a[1]+a[2]+a[3]+a[4]>a[5]){
            b++;
        }if(a[0]+a[1]+a[2]+a[3]+a[4]>a[5]){
            b++;
        }
        cout<<b;
        return 0;
    }
}

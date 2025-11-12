#include<bits/stdc++.h>
#define int long long
using namespace std;


int t;
int n;

int a[100100][4];

int d[100100];
int n1;
void push(int abc){
    n1++;
    d[n1]=abc;
    int x=n1;
    while(x>1){
        if(a[d[x]][1]-a[d[x]][2]<a[d[x/2]][1]-a[d[x/2]][2]){
            swap(d[x],d[x/2]);
            x=x/2;
        }else{
            break;
        }
    }
}
void pop(){
    d[1]=d[n1];
    n1--;
    int x=1;
    while(x*2<=n1){
        if(x*2+1>n1){
            if(a[d[x]][1]-a[d[x]][2]>a[d[x*2]][1]-a[d[x*2]][2]){
                swap(d[x],d[x*2]);
            }
            return;
        }
        int pare;
        if(a[d[x*2+1]][1]-a[d[x*2+1]][2]>a[d[x*2]][1]-a[d[x*2]][2]){
            pare=x*2;
        }else{
            pare=x*2+1;
        }
        if(a[d[x]][1]-a[d[x]][2]>a[d[pare]][1]-a[d[pare]][2]){
            swap(d[x],d[pare]);
        }else{
            return;
        }
        x=pare;
    }
}

signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);

    cin >> t;
    for(int i=1;i<=t;i++){
        cin >> n;
        n1=0;
        int flag=1;
        int cnt1=0,cnt2=0,cnt3=0;
        for(int j=1;j<=n;j++){
            cin >> a[j][1] >> a[j][2] >> a[j][3];
        }
        for(int j=1;j<=n;j++){
            if(a[j][1]>=a[j][2]&&a[j][1]>=a[j][3]){
                cnt1++;
            }else if(a[j][2]>=a[j][1]&&a[j][2]>=a[j][3]){
                cnt2++;
            }else{
                cnt3++;
            }
            if(cnt1>=n/2){
                flag=1;
                break;
            }
            if(cnt2>=n/2){
                flag=2;
                break;
            }
            if(cnt3>=n/2){
                flag=3;
                break;
            }
        }
        if(flag!=1){
            for(int j=1;j<=n;j++){
                swap(a[j][1],a[j][flag]);
            }
        }
        for(int j=1;j<=n;j++){
            if(a[j][2]<a[j][3]){
                swap(a[j][2],a[j][3]);
            }
        }
        /*for(int j=1;j<=n;j++){
            cout << a[j][1] << " " << a[j][2] << " " << a[j][3] <<endl;
        }
        cout << flag << endl;*/
        int ans=0;
        for(int j=1;j<=n;j++){
            if(a[j][1]>a[j][2]){
                push(j);
                ans+=a[j][1];
                if(n1>n/2){
                    ans+=a[d[1]][2];
                    ans-=a[d[1]][1];
                    pop();
                }
            }else{
                ans+=a[j][2];
            }
        }
        cout << ans << endl;
    }

    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

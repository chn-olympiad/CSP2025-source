#include <bits/stdc++.h>
using namespace std;
int cmp(int a,int b){
    return a>b;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m,n;
    cin>>n>>m;
    int a[n*m+10];
    for (int i=1;i<=n*m;i++){
        cin>>a[i];
    }
    int tgt=a[1];
    int smp[n+5][m+5];
    sort(a+1,a+n*m+1,cmp);
    /*
    cout<<"------------------------------"<<endl;
    for (int i=1;i<=n*m;i++){
        cout<<a[i]<<endl;
    }
    cout<<"------------------------------"<<endl;
    */
    smp[1][1]=a[1];
    if (smp[1][1]==tgt){
        cout<<1<<" "<<1<<endl;
        return 0;
    }

    int j=1;
    int i=1;
    int now_cnt=2;
    bool flag=true;
    for (;;){
        if (flag==true){
            if (i<n){

                i++;
                smp[i][j]=a[now_cnt];
                if (a[now_cnt]==tgt){
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
                now_cnt++;
                continue;
            }
            if (i==n){

                flag=false;
                j++;

                smp[i][j]=a[now_cnt];
                if (a[now_cnt]==tgt){
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
                now_cnt++;
                continue;
            }
        }
        else{
            if (i>1){

                i--;
                smp[i][j]=a[now_cnt];
                if (a[now_cnt]==tgt){
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
                now_cnt++;
                continue;
            }
            if(i==1){

                j++;
                flag=true;
                smp[i][j]=a[now_cnt];
                if (a[now_cnt]==tgt){
                    cout<<j<<" "<<i<<endl;
                    return 0;
                }
                now_cnt++;
            }
        }
    }
    return 0;
}

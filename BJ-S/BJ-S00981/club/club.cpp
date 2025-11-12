#include<bits/stdc++.h>
using namespace std;
int t,n,a[1010][1010],maxx[10010],num[100010],fir,sec,thi,bian,maxxx,minn = 2147483647,zong;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    for(int k=1;k<=t;k++){
        cin >> n;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=3;j++){
                cin >> a[i][j];
                if(a[i][j] > maxx[i]){
                    maxx[i] = j;
                    num[i] = a[i][j];
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(maxx[i] == 1){
                fir++;
            }
            if(maxx[i] == 2){
                sec++;
            }
            if(maxx[i] == 3){
                thi++;
            }
        }
        maxxx = max(fir,max(sec,thi));
        bian = n/2;
        if(maxxx > bian){
            for(int i=1;i<=n;i++){
                if(maxx[i] == maxxx){
                    for(int j=1;j<=3;j++){
                        if(maxx[i] == j){
                            continue;
                        }
                        else{
                            minn = min(minn,j);
                        }
                    }
                    maxx[i] = minn;
                    num[i] = a[i][minn];
                }
            }
            for(int i=1;i<=n;i++){
                if(maxx[i] == 1){
                    fir++;
                }
                if(maxx[i] == 2){
                    sec++;
                }
                if(maxx[i] == 3){
                    thi++;
                }
            }
        }
        for(int i=1;i<=n;i++){
            zong += num[i];
        }
        cout << zong << endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+10;
int n,k,ans;
int a[N],kk[25],aa[N][25];
bool flaga=true,flagb=true,flagc=true;
void change(int x,int i){
    int cnt = 0;
    while(x>0){
        aa[i][cnt++] = x%2;
        x/=2;
    }
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin >> n >> k;
    for(int i = 1;i<=n;i++){
        cin >> a[i];
        if(a[i]>1){
            flaga = false;
            flagb = false;
            if(a[i]>255){
                flagc = false;
            }
        }else if(a[i] == 0){
            flaga = false;
        }
    }
    if(flaga){
        if(k==0){
            if(n&1){
                cout << (n-1)/2;
            }else{
                cout << n/2;
            }
        }else{
            for(int i = 1;i<=n;i++){
                if(a[i] == 1){
                    ans++;
                }
            }
            cout << ans;
        }
    }else if(flagb){
        if(k==1){
            for(int i = 1;i<=n;i++){
                if(a[i] == 1){
                    ans++;
                }
            }
        }else{
            for(int i = 1;i<=n;i++){
                if(a[i] == 1 && a[i+1] == 1){
                    ans++;
                    i++;
                }
                if(a[i] == 0){
                    ans++;
                }
            }
        }
        cout << ans;
    }else if(flagc){
        for(int i = 1;i<=n;i++){
            change(a[i],i);
            for(int j = 0;j<8;j++){
                aa[i][j] ^= aa[i-1][j];
            }
        }
        int cnt=0;
        while(k>0){
            kk[cnt++] = k%2;
            k/=2;
        }
        int j = 1,tj=1;
        for(int i = 1;i<=n;i++){
            bool flag = true;
            while(j<=i){
                for(int l = 0;l<8;l++){
                    if(aa[i][l]^aa[j-1][l]!=kk[l]){
                        flag = false;
                        break;
                    }
                }
                j++;
                if(flag){
                    ans++;
                    j = i+1;
                    tj = i+1;
                }
            }
            if(!flag){
                j = tj;
            }
        }
        cout << ans;
    }else{
        for(int i = 1;i<=n;i++){
            change(a[i],i);
            for(int j = 0;j<20;j++){
                aa[i][j] ^= aa[i-1][j];
            }
        }
        int cnt=0;
        while(k>0){
            kk[cnt++] = k%2;
            k/=2;
        }
        int j = 1;
        for(int i = 1;i<=n;i++){
            bool flag = true;
            while(j<=i){
                for(int l = 0;l<20;l++){
                    if(aa[i][l]^aa[j-1][l]!=kk[l]){
                        flag = false;
                        break;
                    }
                }
                j++;
                if(flag){
                    ans++;
                    j = i+1;
                }
            }
            if(!flag){
                j = 1;
            }
        }
        cout << ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int m , n;
    cin >> m >> n;

    int zi = m*n;
    int b[zi+1];

    for(int i=0;i<zi;i++){
        cin >> b[i];
    }

    int r = b[0];

    if(m==n && m==1){
        cout << r;
    }

    int o,cnt=0;
    for(int i = 0;i<zi;i++){
        for(int j = i;j<zi;j++){
            while(b[i]<b[j]){
                if(i==0){
                    cnt++;
                }
                o=b[i];
                b[i] = b[j];
                b[j] = r;
            }
        }
    }
    if ((cnt+1)%n == 0){
        cout << (cnt+1)/n << " ";
        if((cnt+1)%n == 0){
            cout << n;
        }
        else{
            if(n < cnt+1 && cnt+1 <= 2*n){
                cout << n - (cnt+1)%n +1;
            }
            else{
                cout << (cnt+1)%n;
            }
        }
    }
    else{
        cout << (cnt+1)/n+1 << " ";
        if((cnt+1)%n == 0){
            cout << n;
        }
        else{
            if(n < cnt+1 && cnt+1 <= 2*n){
                cout << n - (cnt+1)%n +1;
            }
            else{
                cout << (cnt+1)%n;
            }
        }
    }
    return 0;
}

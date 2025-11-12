#include<bits/stdc++.h>
using namespace std;
int a[1001];
int main(){
    freopen("polygon.in","r",stdin);
    freopen("polygon.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a+1,a+1+n);
    if(n == 3){
        if(a[1]+a[2]+a[3] > a[3]*2)cout << 1 << "\n";
        else cout << 0 << "\n";
    }
    if(n == 4){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    if(a[i]+a[j]+a[k] > a[k]*2)sum++;
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4] > a[4]*2)sum++;
        cout << sum << "\n";
    }
    if(n == 5){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    if(a[i]+a[j]+a[k] > a[k]*2)sum++;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        if(a[i]+a[j]+a[k]+a[b] > a[b]*2)sum++;
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5] > a[5]*2)sum++;
        cout << sum << "\n";
    }
    if(n == 6){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    if(a[i]+a[j]+a[k] > a[k]*2)sum++;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        if(a[i]+a[j]+a[k]+a[b] > a[b]*2)sum++;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            if(a[i]+a[j]+a[k]+a[b]+a[c] > a[c]*2)sum++;
                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6] > a[6]*2)sum++;
        cout << sum << "\n";
    }
    if(n == 7){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    if(a[i]+a[j]+a[k] > a[k]*2)sum++;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        if(a[i]+a[j]+a[k]+a[b] > a[b]*2)sum++;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            if(a[i]+a[j]+a[k]+a[b]+a[c] > a[c]*2)sum++;
                        }
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            for(int d = c+1; d <= n; d++){
                                if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d] > a[d]*2)sum++;
                            }

                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7] > a[7]*2)sum++;
        cout << sum << "\n";
    }
    if(n == 8){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    if(a[i]+a[j]+a[k] > a[k]*2)sum++;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        if(a[i]+a[j]+a[k]+a[b] > a[b]*2)sum++;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            if(a[i]+a[j]+a[k]+a[b]+a[c] > a[c]*2)sum++;
                        }
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            for(int d = c+1; d <= n; d++){
                                if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d] > a[d]*2)sum++;
                            }

                        }
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            for(int d = c+1; d <= n; d++){
                                for(int e = d+1; e <= n; e++){
                                    if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e] > a[e]*2)sum++;
                                }

                            }

                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8] > a[8]*2)sum++;
        cout << sum << "\n";
    }
    if(n == 9){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    if(a[i]+a[j]+a[k] > a[k]*2)sum++;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        if(a[i]+a[j]+a[k]+a[b] > a[b]*2)sum++;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            if(a[i]+a[j]+a[k]+a[b]+a[c] > a[c]*2)sum++;
                        }
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            for(int d = c+1; d <= n; d++){
                                if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d] > a[d]*2)sum++;
                            }

                        }
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            for(int d = c+1; d <= n; d++){
                                for(int e = d+1; e <= n; e++){
                                    if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e] > a[e]*2)sum++;
                                }

                            }

                        }
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            for(int d = c+1; d <= n; d++){
                                for(int e = d+1; e <= n; e++){
                                    for(int f = e+1; f <= n; f++){
                                        if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f] > a[f]*2)sum++;
                                    }

                                }

                            }

                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9] > a[9]*2)sum++;
        cout << sum << "\n";
    }
    if(n == 10){
        int sum = 0;
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    if(a[i]+a[j]+a[k] > a[k]*2)sum++;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        if(a[i]+a[j]+a[k]+a[b] > a[b]*2)sum++;
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            if(a[i]+a[j]+a[k]+a[b]+a[c] > a[c]*2)sum++;
                        }
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            for(int d = c+1; d <= n; d++){
                                if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d] > a[d]*2)sum++;
                            }

                        }
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            for(int d = c+1; d <= n; d++){
                                for(int e = d+1; e <= n; e++){
                                    if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e] > a[e]*2)sum++;
                                }

                            }

                        }
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            for(int d = c+1; d <= n; d++){
                                for(int e = d+1; e <= n; e++){
                                    for(int f = e+1; f <= n; f++){
                                        if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f] > a[f]*2)sum++;
                                    }

                                }

                            }

                        }
                    }
                }
            }
        }
        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                for(int k = j+1; k <= n; k++){
                    for(int b = k+1; b <= n; b++){
                        for(int c = b+1; c <= n; c++){
                            for(int d = c+1; d <= n; d++){
                                for(int e = d+1; e <= n; e++){
                                    for(int f = e+1; f <= n; f++){
                                        for(int g = f+1; g <= n; g++){
                                            if(a[i]+a[j]+a[k]+a[b]+a[c]+a[d]+a[e]+a[f]+a[g] > a[g]*2)sum++;
                                        }

                                    }

                                }

                            }

                        }
                    }
                }
            }
        }
        if(a[1]+a[2]+a[3]+a[4]+a[5]+a[6]+a[7]+a[8]+a[9]+a[10] > a[10]*2)sum++;
        cout << sum << "\n";
    }
    return 0;
}

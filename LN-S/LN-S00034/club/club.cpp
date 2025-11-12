#include <bits/stdc++.h>
using namespace std;
int t,n;
struct A{
    int k1;
    int k2;
    int k3;
} a[100010];
int m1[100010],m2[100010],m3[100010];
int p1,p2,p3;
int sum,maxSum;
int idx1,idx2,idx3,idx = -1;
bool b = true;
bool c = true;
int z[100010];
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >> t;
    while(t--){
        cin >> n;
        for(int i = 0;i < n;i++){
            cin >> a[i].k1 >> a[i].k2 >> a[i].k3;
            if(a[i].k2 != 0){
                b = false;
            }
            if(a[i].k3 != 0){
                c = false;
            }
        }
        if(b && c){
            for(int i = 0;i < n;i++){
                z[i] = a[i].k1;
            }
            for(int i = 0;i < n;i++){
                for(int j =0;j < n;j++){
                    if(z[j] < z[j + 1]){
                        swap(z[j],z[j + 1]);
                    }
                }
            }
            for(int i = 0;i < n / 2;i++){
                sum += z[i];
            }
            cout << sum;
            sum = 0;
            for(int i = 0;i < n;i++){
                a[i].k1 = 0;
                a[i].k2 = 0;
                a[i].k3 = 0;
            }
            continue;
        }
        for(int i = 0;i < n;i++){
            if(a[i].k1 >= a[i].k2 && a[i].k1 >= a[i].k3){
                p1++;
                sum += a[i].k1;
                m1[idx1++] = i;
                if(p1 <= n / 2){
                    continue;
                }else{
                    p1--;
                    for(int j = 0;j < idx1;j++){
                        if(m1[j] != -1){
                            sum -= a[m1[j]].k1;
                            if(a[m1[j]].k2 >= a[m1[j]].k3){
                                p2++;
                                if(sum + a[m1[j]].k2 > maxSum){
                                    sum += a[m1[j]].k2;
                                    maxSum = sum;
                                    idx = j;
                                    m2[idx2++] = a[m1[j]].k2;
                                }else{
                                    sum = maxSum;
                                }
                            }else{
                                p3++;
                                if(sum + a[m1[j]].k3 > maxSum){
                                    sum += a[m1[j]].k3;
                                    maxSum = sum;
                                    idx = j;
                                    m3[idx3++] = a[m1[j]].k2;
                                }else{
                                    sum = maxSum;
                                }
                            }
                        }else{
                            continue;
                        }
                    }
                    m1[idx] = -1;
                    idx = -1;
                }
            }else if(a[i].k2 >= a[i].k1 && a[i].k2 >= a[i].k3){
                p2++;
                sum += a[i].k2;
                m2[idx2++] = i;
                if(p2 <= n / 2){
                    continue;
                }else{
                    p2--;
                    for(int j = 0;j < idx2;j++){
                        sum -= a[m2[j]].k2;
                        if(m2[j] != -1){
                            if(a[m2[j]].k1 >= a[m2[j]].k3){
                                p1++;
                                if(sum + a[m2[j]].k1 > maxSum){
                                    sum += a[m2[j]].k1;
                                    maxSum = sum;
                                    idx = j;
                                    m1[idx1++] = a[m2[j]].k1;
                                }else{
                                    sum = maxSum;
                                }
                            }else{
                                p3++;
                                if(sum + a[m2[j]].k3 > maxSum){
                                    sum += a[m2[j]].k3;
                                    maxSum = sum;
                                    idx = j;
                                    m3[idx3++] = a[m2[j]].k3;
                                }else{
                                    sum = maxSum;
                                }
                            }
                        }else{
                            continue;
                        }
                    }
                    m2[idx] = -1;
                    idx = -1;
                }
            }else if(a[i].k3 >= a[i].k1 && a[i].k3 >= a[i].k2){
                p3++;
                sum += a[i].k3;
                m3[idx3++] = i;
                if(p3 <= n / 2){
                    continue;
                }else{
                    p3--;
                    for(int j = 0;j < idx3;j++){
                        sum -= a[m3[j]].k3;
                        if(m3[j] != -1){
                            if(a[m3[j]].k1 >= a[m3[j]].k2){
                                p1++;
                                if(sum + a[m3[j]].k1 > maxSum){
                                    sum += a[m3[j]].k1;
                                    maxSum = sum;
                                    idx = j;
                                    m1[idx1++] = a[m3[j]].k1;
                                }else{
                                    sum = maxSum;
                                }
                            }else{
                                p2++;
                                if(sum + a[m3[j]].k2 > maxSum){
                                    sum += a[m3[j]].k2;
                                    maxSum = sum;
                                    idx = j;
                                    m2[idx2++] = a[m3[j]].k2;
                                }else{
                                    sum = maxSum;
                                }
                            }
                        }else{
                            continue;
                        }
                    }
                    m3[idx] = -1;
                    idx = -1;
                }
            }
        }
        cout << sum << endl;
        sum = 0;
        p1 = 0;
        p2 = 0;
        p3 = 0;
        maxSum = 0;
        idx = -1;
        idx1 = 0;
        idx2 = 0;
        idx3 = 0;
        for(int i = 0;i < n;i++){
            a[i].k1 = 0;
            a[i].k2 = 0;
            a[i].k3 = 0;
        }
    }
    return 0;
}

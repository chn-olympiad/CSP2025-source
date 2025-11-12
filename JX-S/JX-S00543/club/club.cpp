#include <bits/stdc++.h>
using namespace std;
int t, n, fir, sec, thi, h, l1[100005];
struct club{
    int a1, a2, a3, p;
}a[100005];
void fi1(){
    int ns, x = 100005, nr;
    for(int i = 1; i <= n; i ++){
        if(a[i].p == 1){
            if((a[i].a1 - a[i].a2) < (a[i].a1 - a[i].a3)){
                if(x > (a[i].a1 - a[i].a2)){
                    ns = i;
                    nr = 2;
                    x = a[i].a1 - a[i].a2;
                }
            }else{
                if(x > (a[i].a1 - a[i].a3)){
                    ns = i;
                    nr = 3;
                    x = a[i].a1 - a[i].a3;
                }
            }
        }

    }
    a[ns].a1 = -1;
    if(nr == 3){
        a[ns].p = 3;
        thi ++;
    }else{
        a[ns].p = 2;
        sec ++;
    }
    fir --;
}

void fi2(){
    int ns, x = 100005, nr;
    for(int i = 1; i <= n; i ++){
        if(a[i].p == 2){
            if((a[i].a2 - a[i].a1) < (a[i].a2 - a[i].a3)){
                if(x > (a[i].a2 - a[i].a1)){
                    ns = i;
                    nr = 1;
                    x = a[i].a2 - a[i].a1;
                }
            }else{
                if(x > (a[i].a2 - a[i].a3)){
                    ns = i;
                    nr = 3;
                    x = a[i].a2 - a[i].a3;
                }
            }
        }

    }
    a[ns].a2 = -1;
    if(nr == 3){
        a[ns].p = 3;
        thi ++;
    }else{
        a[ns].p = 1;
        fir ++;
    }
    sec --;
}

void fi3(){
    int ns, x = 100005, nr;
    for(int i = 1; i <= n; i ++){
        if(a[i].p == 3){
            if((a[i].a3 - a[i].a1) < (a[i].a3 - a[i].a2)){
                if(x > (a[i].a3 - a[i].a1)){
                    ns = i;
                    nr = 1;
                    x = a[i].a3 - a[i].a1;
                }
            }else{
                if(x > (a[i].a3 - a[i].a2)){
                    ns = i;
                    nr = 2;
                    x = a[i].a3 - a[i].a2;
                }
            }
        }

    }
    a[ns].a3 = -1;
    if(nr == 2){
        a[ns].p = 2;
        sec ++;
    }else{
        a[ns].p = 1;
        fir ++;
    }
    thi --;
}

void exic(){
    while(1){
        if(fir <= h && sec <= h && thi <= h) return;
        if(fir > h){
            fi1();
        }
        if(sec > h){
            fi2();
        }
        if(thi > h){
            fi3();
        }
    }

}
int main(){
    freopen("club.in", "r", stdin);
    freopen("club.out", "w", stdout);
    cin >> t;
    while(t --){
        cin >> n;
        h = n / 2;
        for(int i = 1; i <= n; i ++){
            cin >> a[i].a1 >> a[i].a2 >> a[i].a3;
            int temp = max(a[i].a1, max(a[i].a2, a[i].a3));
            if(temp == a[i].a1){
                fir ++;
                a[i].p = 1;
            }else if(temp == a[i].a2){
                sec ++;
                a[i].p = 2;
            }else{
                thi ++;
                a[i].p = 3;
            }
        }
        exic();
        int tem = 0;
        for(int i = 1; i <= n; i ++){
            if(a[i].p == 1){
                if(a[i].a1 == -1){
                    tem ++;
                }
                tem += a[i].a1;
            }else if(a[i].p == 2){
                if(a[i].a2 == -1){
                    tem ++;
                }
                tem += a[i].a2;
            }else{
                if(a[i].a3 == -1){
                    tem ++;
                }
                tem += a[i].a3;
            }
        }
        cout << tem << endl;
        fir = sec = thi = 0;
    }
    return 0;
}

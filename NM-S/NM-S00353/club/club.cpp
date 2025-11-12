#include <bits/stdc++.h>
using namespace std;

const int maxn=1e5+5;

int t;
int n;

struct Student{
    int a1,a2,a3;
    int f;
} a[maxn];

struct Cnt{
    int cnt,c;
};

Cnt  c1[maxn],c2[maxn],c3[maxn];

long long sum;
int k1,k2,k3;

bool cmp(Cnt x,Cnt y){
    return x.cnt>y.cnt;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin >>t;
    while(t!=0){
        sum=0;
        k1=0;
        k2=0;
        k3=0;
        t--;
        cin >>n;
        for(int i=1;i<=n;i++){
            cin >>a[i].a1 >>a[i].a2 >>a[i].a3;
            int Max=max(max(a[i].a1,a[i].a2),a[i].a3);
            if(Max==a[i].a1){
                c1[k1].cnt=a[i].a1;c1[k1].c=i;k1++;
            }
            else if(Max==a[i].a2){
                c2[k2].cnt=a[i].a2;c2[k2].c=i;k2++;
            }
            else{
                c3[k3].cnt=a[i].a3;c3[k3].c=i;k3++;
            }
        }
        while(k3>n/2 || k2>n/2 || k1>n/2){
            if(k3 > n/2){
                sort(c3,c3+k3,cmp);
                while(k3>n/2){
                    k3--;
                    int Max=max(max(a[c3[k3].c].a1,a[c3[k3].c].a2),a[c3[k3].c].a3);
                    if(Max==a[c3[k3].c].a3){
                        if(a[c3[k3].c].a2>=a[c3[k3].c].a1){
                            c2[k2].c=c3[k3].c;
                            c2[k2].cnt=a[c3[k3].c].a2;
                            k2++;
                        }else{
                            c1[k1].c=c3[k3].c;
                            c1[k1].cnt=a[c3[k3].c].a1;
                            k1++;
                        }
                    }else{
                        if(a[c3[k3].c].a1>=a[c3[k3].c].a2){
                            c2[k2].c=c3[k3].c;
                            c2[k2].cnt=a[c3[k3].c].a2;
                            k2++;
                        }else{
                            c1[k1].c=c3[k3].c;
                            c1[k1].cnt=a[c3[k3].c].a1;
                            k1++;
                        }
                    }
                }
            }else if(k2 > n/2){
                sort(c2,c2+k2,cmp);
                while(k2>n/2){
                    k2--;
                    int Max=max(max(a[c2[k2].c].a1,a[c2[k2].c].a2),a[c2[k2].c].a3);
                    if(Max==a[c2[k2].c].a2){
                        if(a[c2[k2].c].a3>=a[c3[k3].c].a1){
                            c3[k3].c=c2[k2].c;
                            c3[k3].cnt=a[c2[k2].c].a3;
                            k3++;
                        }else{
                            c1[k1].c=c2[k2].c;
                            c1[k1].cnt=a[c2[k2].c].a1;
                            k1++;
                        }
                    }else{
                        if(a[c2[k2].c].a1>=a[c2[k2].c].a3){
                            c3[k3].c=c2[k2].c;
                            c2[k3].cnt=a[c2[k2].c].a3;
                            k3++;
                        }else{
                            c1[k1].c=c2[k2].c;
                            c1[k1].cnt=a[c2[k2].c].a1;
                            k1++;
                        }
                    }
                }
            }else{
                sort(c1,c1+k1,cmp);
                while(k1>n/2){
                    k1--;
                    int Max=max(max(a[c1[k1].c].a1,a[c1[k1].c].a2),a[c1[k1].c].a3);
                    if(Max==a[c1[k1].c].a1){
                        if(a[c1[k1].c].a2>=a[c1[k1].c].a3){
                            c2[k2].c=c1[k1].c;
                            c2[k2].cnt=a[c1[k1].c].a2;
                            k2++;
                        }else{
                            c3[k3].c=c1[k1].c;
                            c3[k3].cnt=a[c1[k1].c].a3;
                            k3++;
                        }
                    }else{
                        if(a[c1[k1].c].a3>=a[c1[k1].c].a2){
                            c2[k2].c=c1[k1].c;
                            c2[k2].cnt=a[c1[k1].c].a2;
                            k2++;
                        }else{
                            c1[k3].c=c1[k1].c;
                            c1[k3].cnt=a[c1[k1].c].a3;
                            k3++;
                        }
                    }
                }
            }
        }
        for(int i=0;i<k1;i++){
            sum=sum+c1[i].cnt;
        }
        for(int i=0;i<k2;i++){
            sum=sum+c2[i].cnt;
        }
        for(int i=0;i<k3;i++){
            sum=sum+c3[i].cnt;
        }
        cout <<sum <<endl;;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

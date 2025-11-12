#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct node{
    int x,y,z,m,mi,mi2,mi3;
}a[200005];
struct edge{
    int id,v;
}b[200005][3];
bool cmp(node a,node b){
    return a.m>b.m;
}
bool cmp2(edge a,edge b){
    return a.v>b.v;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >>t;
    while(t--){
        int n,a1 = 0,b1 = 0,c1 = 0,sum= 0;
        int ax=0,bx=0,cx=0;
        cin >>n;
        for (int i = 1;i<=n ;i++){
            cin >> a[i].x >>a[i].y >> a[i].z;
            int n,a1 = 0,b1 = 0,c1 = 0,sum= 0;
            int ax=0,bx=0,cx=0;
            b[i][0].v = a[i].x;b[i][1].v = a[i].y;b[i][2].v = a[i].z;
            b[i][0].id = 1;b[i][1].id = 2;b[i][2].id = 3;
            sort(b[i],b[i]+3,cmp2);

        }
        for (int i = 1;i<=n;i++){
            if (b[i][0].id==1){
                if (a1<=n/2){
                    a1++;
                    sum+=b[i][0].v;
                }
                else{
                    if (b[i][1].id==2){
                        if (b1<=n/2){
                            b1++;
                            sum+=b[i][1].v;
                        }
                        else{
                            if (c1<=n/2){
                                c1++;
                                sum+=b[i][2].v;
                            }
                        }
                    }
                }
            }
            if (b[i][0].id==2){
                if (b1<=n/2){
                    b1++;
                    sum+=b[i][0].v;
                }
                else{
                    if (b[i][1].id==1){
                        if (a1<=n/2){
                            a1++;
                            sum+=b[i][1].v;
                        }
                        else{
                            if (c1<=n/2){
                                c1++;
                                sum+=b[i][2].v;
                            }
                        }
                    }
                }
            }
            if (b[i][0].id==3){
                if (c1<=n/2){
                        c1++;
                    sum+=b[i][0].v;
                }
                else{
                    if (b[i][1].id==2){
                        if (b1<=n/2){
                            b1++;
                            sum+=b[i][1].v;
                        }
                        else{
                            if (a1<=n/2){
                                a1++;
                                sum+=b[i][2].v;
                            }
                        }
                    }
                }
            }
        }
        cout <<sum<<endl;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
struct st{
    int f,s,f1,s1,q;
}d[100000];
bool cmp(st x,st y){
    return x.q>=y.q;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T,n;
    cin >> T;
    while(T>0){
        cin>>n;
        int a,b,c;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            d[i].f=max(a,max(b,c));
            if(d[i].f==a){
                d[i].f1=1;
                if(b>c){
                    d[i].s=b;
                    d[i].s1=2;
                }else{
                    d[i].s=c;
                    d[i].s1=3;
                }
            }else if(d[i].f==b){
                d[i].f1=2;
                if(a>c){
                    d[i].s=a;
                    d[i].s1=1;
                }else{
                    d[i].s=c;
                    d[i].s1=3;
                }
            }else{
                d[i].f1=3;
                if(a>b){
                    d[i].s=a;
                    d[i].s1=1;
                }else{
                    d[i].s=b;
                    d[i].s1=2;
                }
            }
            d[i].q=d[i].f-d[i].s;

        }
        sort(d,d+n,cmp);

        int j1=0,j2=0,j3=0,cnt=0;
        for(int i=0;i<n;i++){
            if(d[i].f1==1){
                j1++;
                if(j1<=n/2) cnt+=d[i].f;
                else{
                    d[i].f=d[i].s;
                    d[i].f1=d[i].s1;
                    i--;
                    j1--;
                }
            }else if(d[i].f1==2){
                j2++;
                if(j2<=n/2) cnt+=d[i].f;
                else{
                    d[i].f=d[i].s;
                    d[i].f1=d[i].s1;
                    i--;
                    j2--;
                }
            }else{
                j3++;
                if(j3<=n/2) cnt+=d[i].f;
                else{
                    d[i].f=d[i].s;
                    d[i].f1=d[i].s1;
                    i--;
                    j3--;
                }
            }
        }
        cout << cnt << endl;
        T--;
    }
    return 0;
}

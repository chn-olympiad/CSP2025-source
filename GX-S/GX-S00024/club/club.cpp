#include<bits/stdc++.h>
using namespace std;
struct node{
    int sum1,sum2,sum3;
    int maxn,num2;
    bool c=false;
    int x,y;
}a[1001];
int num1;
int n,m1,m2,m3;
int tool;
bool cmp(node a,node b){
    return a.maxn>b.maxn;
}
int main(){
    //freopen("club.in","r",stdin);
    //freopen("club.out","w",stdout);
    cin>>tool;
    while(tool--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].sum1>>a[i].sum2>>a[i].sum3;
            if(a[i].sum2>a[i].sum1 && a[i].sum2>a[i].sum3){
                a[i].maxn=a[i].sum2;
                a[i].num2=2;
                a[i].x=2;
            }else if(a[i].sum1>a[i].sum2&&a[i].sum1>a[i].sum3){
                a[i].maxn=a[i].sum1;
                a[i].num2=1;
                a[i].x=1;
            }else{
                a[i].maxn=a[i].sum3;
                a[i].num2=3;
                a[i].x=3;
            }
        }
        sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            int p=a[i].num2;
            if(p==1){
                if(m1<(n/2)){
                    m1++;
                    num1+=a[i].maxn;
                    a[i].c=true;
                }
            }else if(p==2){
                if(m2<(n/2)){
                    m2++;
                    num1+=a[i].maxn;
                    a[i].c=true;
                }
            }else{
                if(m3<(n/2)){
                    m3++;
                    num1+=a[i].maxn;
                    a[i].c=true;
                }
            }
        }
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(a[i].c=false){
                flag=true;
                if(a[i].num2==1){
                    if(a[i].sum2>a[i].sum3){
                        a[i].num2=2;
                        a[i].maxn=a[i].sum2;
                        a[i].y=2;
                    }else{
                        a[i].num2=3;
                        a[i].maxn=a[i].sum3;
                        a[i].y=3;
                    }
                }else if(a[i].num2==2){
                    if(a[i].sum1>a[i].sum3){
                        a[i].num2=1;
                        a[i].maxn=a[i].sum1;
                        a[i].y=1;
                    }else{
                        a[i].num2=3;
                        a[i].maxn=a[i].sum3;
                        a[i].y=3;
                    }
                }else{
                    if(a[i].sum2>a[i].sum1){
                        a[i].num2=2;
                        a[i].maxn=a[i].sum2;
                        a[i].y=2;
                    }else{
                        a[i].num2=1;
                        a[i].maxn=a[i].sum1;
                        a[i].y=1;
                    }
                }
            }
        }
        if(flag) sort(a+1,a+1+n,cmp);
        for(int i=1;i<=n;i++){
            if(flag){
                if(a[i].c==false){
                    cout<<1;
                    int p=a[i].num2;
                    if(p==1){
                        if(m1<(n/2)){
                            m1++;
                            num1+=a[i].maxn;
                            a[i].c=true;
                        }
                    }else if(p==2){
                        if(m2<(n/2)){
                            m2++;
                            num1+=a[i].maxn;
                            a[i].c=true;
                        }
                    }else{
                        if(m3<(n/2)){
                            m3++;
                            num1+=a[i].maxn;
                            a[i].c=true;
                        }
                    }
                }
            }

        }

        for(int i=1;i<=n;i++){
            if(a[i].c==false){
                if(a[i].x==1){
                    if(a[i].y==2){
                        m3++;
                        num1+=a[i].sum3;
                    }
                    if(a[i].y==3){
                        m2++;
                        num1+=a[i].sum2;
                    }
                }else if(a[i].x==2){
                    if(a[i].y==1){
                        m3++;
                        num1+=a[i].sum3;
                    }
                    if(a[i].y==3){
                        m1++;
                        num1+=a[i].sum1;
                    }
                }else{
                    if(a[i].y==2){
                        m1++;
                        num1+=a[i].sum1;
                    }
                    if(a[i].y==1){
                        m2++;
                        num1+=a[i].sum2;
                    }
                }
            }
        }
        cout<<num1<<endl;
    }
    //fclose(stdin);
    //fclose(stdout);
    return 0;
}

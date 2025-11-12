#include<bits/stdc++.h>
using namespace std;
int t,n,sum,a1,b1,c1;
struct Node
{
    int a,b,c,s;
}a[1000000];
bool cmpa(Node a,Node b){
    return a.s-a.a>b.s-b.a;
}
bool cmpb(Node a,Node b){
    return a.s-a.b>b.s-b.b;
}
bool cmpc(Node a,Node b){
    return a.s-a.c>b.s-b.c;
}
bool cmpa1(Node a,Node b){
    return a.a>b.a;
}
bool cmpb1(Node a,Node b){
    return a.b>b.b;
}
bool cmpc1(Node a,Node b){
    return a.c>b.c;
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        sum=0;a1=0;b1=0;c1=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            a[i].s=a[i].a+a[i].b+a[i].c;
        }
        if(a[0].b==0&&a[1].b==0&&a[0].c==0&&a[1].c==0){
            sort(a,a+n,cmpa1);
            for(int i=0;i<n/2;i++){
                sum+=a[i].a;
            }
            cout<<sum;
            continue;
        }
        for(int i=0;i<n;i++){
            if(a[i].a>=a[i].b&&a[i].a>=a[i].c){
                a1++;
                sum+=a[i].a;
            }
            else if(a[i].b>=a[i].c&&a[i].b>=a[i].a){
                b1++;
                sum+=a[i].b;
            }
            else if(a[i].c>=a[i].b&&a[i].c>=a[i].a){
                c1++;
                sum+=a[i].c;
            }
        }
        if(a1>n/2){
            sort(a,a+n,cmpa1);
            sort(a,a+n,cmpa);
            for(int i=0;i<a1-n/2;i++){
                if(a[i].b>a[i].c&&b1<n/2){
                    b1++;
                    sum-=a[i].a;
                    sum+=a[i].b;
                }
                if(a[i].b<a[i].c&&c1<n/2){
                    c1++;
                    sum-=a[i].a;
                    sum+=a[i].c;
                }
                if(a[i].b==a[i].c){
                    if(b1>=c1){
                        c1++;
                        sum-=a[i].a;
                        sum+=a[i].c;
                    }
                    if(b1<c1){
                        b1++;
                        sum-=a[i].a;
                        sum+=a[i].b;
                    }
                }
                a[i].a=10000000;
            }
        }
        if(b1>n/2){
            sort(a,a+n,cmpb1);
            sort(a,a+n,cmpb);
            for(int i=0;i<b1-n/2;i++){
                if(a[i].a>a[i].c&&a1<n/2){
                    a1++;
                    sum-=a[i].b;
                    sum+=a[i].a;
                }
                if(a[i].a<a[i].c&&c1<n/2){
                    c1++;
                    sum-=a[i].b;
                    sum+=a[i].c;
                }
                if(a[i].a==a[i].c){
                    if(a1>=c1){
                        c1++;
                        sum-=a[i].b;
                        sum+=a[i].c;
                    }
                    if(a1<c1){
                        a1++;
                        sum-=a[i].b;
                        sum+=a[i].c;
                    }
                }
                a[i].b=1000000;
            }
        }
        if(c1>n/2){
            sort(a,a+n,cmpc1);
            sort(a,a+n,cmpc);
            for(int i=0;i<c1-n/2;i++){
                if(a[i].b>a[i].a&&b1<n/2){
                    b1++;
                    sum-=a[i].c;
                    sum+=a[i].b;
                }
                if(a[i].b<a[i].a&&a1<n/2){
                    a1++;
                    sum-=a[i].c;
                    sum+=a[i].a;
                }
                if(a[i].a==a[i].b){
                    if(b1>=a1){
                        a1++;
                        sum-=a[i].c;
                        sum+=a[i].a;
                    }
                    if(b1<a1){
                        b1++;
                        sum-=a[i].c;
                        sum+=a[i].b;
                    }
                }
                a[i].c=10000000;
            }
        }
        cout<<sum<<endl;
    }
}

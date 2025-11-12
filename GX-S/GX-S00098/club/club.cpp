#include<bits/stdc++.h>
using namespace std;
struct node{
    int a,b,c;
    int maxx=-1;
    int mid=-1;
    int id;
    int minn=1145141;
};
bool cmp(node x,node y){
    if(x.maxx-x.mid!=y.maxx-y.mid){
      return x.maxx-x.mid>y.maxx-y.mid;
    }

}bool cmp3(node x,node y){
    return x.maxx>y.maxx;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        node a[n+5];
        int ans=0;
        bool flag=1;
        for(int i=0;i<n;i++){

            cin>>a[i].a>>a[i].b>>a[i].c;a[i].minn=min(a[i].a,min(a[i].b,a[i].c));
        if(a[i].c!=0){
            flag=0;
        }
            a[i].maxx=max(a[i].a,max(a[i].b,a[i].c));
    a[i].id=i;
            ans+=a[i].minn;
            if(a[i].a!=a[i].maxx&&a[i].a!=a[i].minn){
                a[i].mid=a[i].a;
            }else if(a[i].b!=a[i].maxx&&a[i].b!=a[i].minn){
                a[i].mid=a[i].b;
            }else{
                a[i].mid=a[i].c;
            }a[i].mid-=a[i].minn;
            a[i].maxx-=a[i].minn;
        }sort(a,a+n,cmp);
        if(flag){
            for(int i=0;i<n;i++){

          a[i].minn=min(a[i].a,min(a[i].b,a[i].b));
            a[i].maxx=max(a[i].a,a[i].b);
    a[i].id=i;
            ans+=a[i].minn;
            if(a[i].a==a[i].maxx){
                a[i].mid=a[i].b;
            }else{
                a[i].mid=a[i].a;
            }
            a[i].maxx-=a[i].minn;
            a[i].mid-=a[i].minn;
        }sort(a,a+n,cmp3);
        }
        int c1=0,c2=0,c3=0;
        for(int i=0;i<n;i++){

            if(a[i].maxx==a[i].a-a[i].minn){

                    if(c1+1<=n/2){
                        ans+=a[i].maxx;
                        c1++;

                    }else{
                        if(a[i].mid==a[i].b-a[i].minn){
                               if(c2+1<=n/2){
                            c2++;
                            ans+=a[i].mid;}
                        }else{
                            if(c3+1<=n/2){
                                c3++;
                                ans+=a[i].mid;
                                }
                        }
                    }
            }else if(a[i].maxx==a[i].b-a[i].minn){
                if(c2+1<=n/2){
                        ans+=a[i].maxx;
                        c2++;
                    }else{
                        if(a[i].mid==a[i].a-a[i].minn){
                              if(c1+1<=n/2){
                                c1++;
                                ans+=a[i].mid;
                                }
                        }else{
                            if(c3+1<=n/2){
                                c3++;
                                ans+=a[i].mid;
                                }
                        }
                    }
            }else{
                if(c3+1<=n/2){
                        ans+=a[i].maxx;
                        c3++;
                    }else{
                        if(a[i].mid==a[i].a-a[i].minn){
                                if(c1+1<=n/2){
                                c1++;
                                ans+=a[i].mid;
                                }
                        }else{if(c2+1<=n/2){
                            c2++;
                            ans+=a[i].mid;}
                        }
                    }
            }
        }
        cout<<ans<<endl;
    }
}

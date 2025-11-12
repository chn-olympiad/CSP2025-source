#include <bits/stdc++.h>
using namespace std;
int t,n;
struct peo{
    int a,b,c;
    int ab,ac,bc;
    short num[3];
    bool vis;
    short have;
    int maxn[3];
}a[100005];
bool cmp(peo a,peo b){
    if(a.have!=b.have)
    return a.have<b.have;
    for(int i=0;i<=2;i++){
        if(a.maxn[i]!=b.maxn[i]){
            return a.maxn[i]>b.maxn[i];
        }
    }
    return 0;
}
void boom(){
    exit(0);
}
bool flag=1;
bool cmpab(peo a,peo b){
    return a.ab>b.ab;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    // t=1;
    while(t--){
        // a.clear();
        int club[3]={0};
        long long sum=0;
        flag=1;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].a>>a[i].b>>a[i].c;
            // cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<endl;
            if(a[i].c!=0) {
                // cout<<"NO"<<endl;
                flag=0;}
            a[i].ab=a[i].a-a[i].b;
            a[i].ac=a[i].a-a[i].c;
            a[i].bc=a[i].b-a[i].c;
            if(a[i].a>a[i].b){//a>b
                if(a[i].a>a[i].c){//a>c
                    a[i].num[0]=1;
                    if(a[i].b>a[i].c){
                        a[i].num[1]=2,a[i].num[2]=3;
                    }
                }
                else{//a<c
                    a[i].num[0]=2,a[i].num[1]=3,a[i].num[2]=1;
                }

            }
            else{//a<b
                if(a[i].a<a[i].c){
                    a[i].num[0]=3;
                    if(a[i].b<a[i].c){
                        a[i].num[1]=2,a[i].num[2]=1;
                    }
                    else{
                        a[i].num[1]=1,a[i].num[2]=2;
                    }
                }
                else{//a>c
                    a[i].num[0]=2,a[i].num[1]=1,a[i].num[2]=3;
                }
            }
            if(a[i].a) a[i].have++;
            if(a[i].b) a[i].have++;
            if(a[i].c) a[i].have++;
            for(int j=0;j<=2;j++){
                // if(a[i].num[j]==1){
                //     a[i].maxn[0]=a[i].a;
                // }
                // if(a[i].num[j]==2){
                //     a[i].maxn[1]=a[i].b;
                // }
                // if(a[i].num[j]==3){
                //     a[i].maxn[2]=a[i].c;
                // }
                if(j==0){
                    a[i].maxn[a[i].num[j]-1]=a[i].a;
                }
                if(j==1){
                    a[i].maxn[a[i].num[j]-1]=a[i].b;
                }
                if(j==0){
                    a[i].maxn[a[i].num[j]-1]=a[i].c;
                }
            }

        }
        // sort(a,a+n,cmp);
        // for(int i=0;i<n;i++){
        //     cout<<a[i].a<<' '<<a[i].b<<' '<<a[i].c<<endl;
        // }
        // boom();
        // cout<<flag<<endl;
        if(flag==1){
            // cout<<1<<endl;
            sort(a,a+n,cmpab);
            for(int i=0;i<n/2;i++){
                sum+=a[i].a;
            }
            for(int i=n/2;i<n;i++){
                sum+=a[i].b;
            }
            cout<<sum<<endl;
        }
        else{
        
            sort(a,a+n,cmp);
            for(int i=0;i<n;i++){
                bool isjoin=0;
                int last=1;
                for(int j=0;j<=2;j++){
                    if(club[j]<n/2&&a[i].num[j]==last){
                        club[j]++;
                        if(j==0){
                            // cout<<i<<':'<<a[i].a<<endl;
                            sum+=a[i].a;
                            isjoin=1;
                            break;
                        }
                        if(j==1){
                            // cout<<i<<':'<<a[i].b<<endl;
                            sum+=a[i].b;
                            isjoin=1;
                            break;
                        }
                        if(j==2){
                            // cout<<i<<':'<<a[i].c<<endl;
                            sum+=a[i].c;
                            isjoin=1;
                            break;
                        }
                    }
                    if(a[i].num[j]==last&&!isjoin){
                        j=0;
                        last++;
                    }
                }
            }
            cout<<sum<<endl;
        }

    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct z{
    int po,val;
}c1[N],c2[N],c3[N];
struct T{
    int cl1,cl2,cl3,pos1,pos2,pos3;
}a[N];
int t,n,ans=0,f=0,b[N];
bool tmp(z x,z y){
    return x.val>y.val;
}
int find(int x){
    if(a[x].cl1>a[x].cl2){
        if(a[x].cl1>a[x].cl3) return 1;
        else    return 3;
    }
    else{
        if(a[x].cl2>a[x].cl3) return 2;
        else    return 3;
    }
}
void kd(){
    for(int i=1;i<=n;i++){
        b[i]=c1[i].val;
    }
    sort(b+1,b+n+1);
    int k=n/2;
    for(int i=k+1;i<=n;i++){
        ans+=b[i];
    }
    cout<<ans<<endl;
    return ;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        ans=0;
        f=0;
        for(int i=1;i<=n;i++){
            c1[i].po=i;
            c2[i].po=i;
            c3[i].po=i;
            cin>>c1[i].val>>c2[i].val>>c3[i].val;
            if(c2[i].val!=0||c3[i].val!=0)  f=1;
            a[i].cl1=c1[i].val;
            a[i].cl2=c2[i].val;
            a[i].cl3=c3[i].val;
        }
        if(f==0){
            kd();
            continue;
        }
        sort(c1+1,c1+n+1,tmp);
        for(int i=1;i<=n;i++){
            a[c1[i].po].pos1=i;
        }
        sort(c2+1,c2+n+1,tmp);
        for(int i=1;i<=n;i++){
            a[c2[i].po].pos2=i;
        }
        sort(c3+1,c3+n+1,tmp);
        for(int i=1;i<=n;i++){
            a[c3[i].po].pos3=i;
        }
        for(int i=1;i<=n;i++){
            int k=find(i);
            if(k==1){
                if(a[i].pos1<=n/2){
                    ans+=a[i].cl1;

                }
                else{
                    if(a[i].cl2>a[i].cl3){
                        if(a[i].pos2<=n/2){
                            ans+=a[i].cl2;
                        }
                        else{
                            if(a[i].pos3<=n/2){
                                ans+=a[i].cl3;
                            }
                        }
                    }
                    else{
                        if(a[i].pos3<=n/2){
                            ans+=a[i].cl3;
                        }
                        else{
                            if(a[i].pos2<=n/2){
                                ans+=a[i].cl2;
                            }
                        }
                    }
                }
            }
            if(k==2){
                if(a[i].pos2<=n/2){
                    ans+=a[i].cl2;
                }
                else{
                    if(a[i].cl1>a[i].cl3){
                        if(a[i].pos1<=n/2){
                            ans+=a[i].cl1;
                        }
                        else{
                            if(a[i].pos3<=n/2){
                                ans+=a[i].cl3;
                            }
                        }
                    }
                    else{
                        if(a[i].pos3<=n/2){
                            ans+=a[i].cl3;
                        }
                        else{
                            if(a[i].pos1<=n/2){
                                ans+=a[i].cl1;
                            }
                        }
                    }
                }
            }
            if(k==3){
                if(a[i].pos3<=n/2){
                    ans+=a[i].cl3;
                }
                else{
                    if(a[i].cl1>a[i].cl2){
                        if(a[i].pos1<=n/2){
                            ans+=a[i].cl1;
                        }
                        else{
                            if(a[i].pos2<=n/2){
                                ans+=a[i].cl2;
                            }
                        }
                    }
                    else{
                        if(a[i].pos2<=n/2){
                            ans+=a[i].cl2;
                        }
                        else{
                            if(a[i].pos1<=n/2){
                                ans+=a[i].cl1;
                            }
                        }
                    }
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
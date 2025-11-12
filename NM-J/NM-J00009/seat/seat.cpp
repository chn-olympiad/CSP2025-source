#include<bits/stdc++.h>
using namespace std;
struct p{
    int k,id,s;
};
bool cmp(p x,p y){
    return x.id>y.id;
}
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    long long n=0,m=0,a=0;
    scanf("%d%d",&n,&m);
    scanf("%d",&a);
    p aa={};
    aa.id=a;
    aa.k=0;
    vector<p> v={};
    v.push_back(aa);
    for(int i=1;i<n*m;i++){
        int t=0;
        scanf("%d",&t);
        p tt={};
        tt.id=t;
        tt.k=i;
        v.push_back(tt);
    }
    sort(v.begin(),v.end(),cmp);

    for(int i=0;i<n*m;i++){
        v[i].s=i+1;
        //cout<<v[i].id<<" "<<v[i].s<<"\n";
    }
    for(int i=0;i<n*m;i++){
        if(v[i].k==0){
            int c=0,r=0;
            c=ceil(v[i].s/n*1.0);
            if(v[i].s%n==0){
                if(c%2==1){
                    r=n;
                }else{
                    r=n-v[i].s/n+1;
                }
                printf("%d %d",c,r);
            }else{
                c++;
                if(c%2==1){
                    //cout<<r<<" ";
                    r=v[i].s%n;
                }else{
                    r=n-v[i].s%n+1;
                }
                printf("%d %d",c,r);
                //cout<<n<<" "<<v[i].s%n<<" ";
            }
            break;
        }
    }

    return 0;
}

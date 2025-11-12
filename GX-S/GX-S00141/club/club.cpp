#include<bits/stdc++.h>
using namespace std;
struct lnh{
    long long a,b,c;
}mem[100005];
long long f[100005][2];
bool cmp1(lnh a,lnh b){
    return a.a>b.a;
}
bool cmp2(lnh a,lnh b){
    return a.b>b.b;
}
int main(){
    freopen("club4.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        int n3=0,n2=0;
        cin>>n;
        for(int i = 1;i<=n;i++){
            cin>>mem[i].a>>mem[i].b>>mem[i].c;
            if(mem[i].b==0){
                n2++;
            }
            if(mem[i].c==0){
                n3++;
            }
        }
        if(n==2){
            long long sum=0;
            sum=max(sum,max(mem[1].a+mem[2].b,mem[1].a+mem[2].c));
            sum=max(sum,max(mem[1].b+mem[2].c,mem[1].b+mem[2].a));
            sum=max(sum,max(mem[1].c+mem[2].b,mem[1].c+mem[2].a));
            cout<<sum<<endl;
        }
        if(n==4){
            long long sum=0;
            sum=max(sum,max(mem[1].a+mem[2].a+mem[3].b+mem[4].b,
                            mem[1].a+mem[2].a+mem[3].c+mem[4].c));
            sum=max(sum,max(mem[1].a+mem[2].a+mem[3].b+mem[4].c,
                            mem[1].a+mem[2].a+mem[3].c+mem[4].b));

            sum=max(sum,max(mem[1].a+mem[2].b+mem[3].b+mem[4].c,
                            mem[1].a+mem[2].b+mem[3].b+mem[4].a));
            sum=max(sum,max(mem[1].a+mem[2].b+mem[3].c+mem[4].b,
                            mem[1].a+mem[2].b+mem[3].a+mem[4].b));

            sum=max(sum,max(mem[1].a+mem[2].c+mem[3].a+mem[4].b,
                            mem[1].a+mem[2].c+mem[3].b+mem[4].a));
            sum=max(sum,max(mem[1].a+mem[2].c+mem[3].c+mem[4].b,
                            mem[1].a+mem[2].c+mem[3].b+mem[4].c));

            sum=max(sum,max(mem[1].a+mem[2].c+mem[3].b+mem[4].b,
                            mem[1].a+mem[2].b+mem[3].c+mem[4].c));

            sum=max(sum,max(mem[1].a+mem[2].c+mem[3].c+mem[4].b,
                            mem[1].a+mem[2].c+mem[3].b+mem[4].c));
            cout<<sum<<endl;
        }
        if(n2==n&&n3==n){
            sort(mem+1,mem+n+1,cmp1);
            long long sum=0;
            for(int i=1;i<=n/2;i++){
                sum+=mem[i].a;
            }
            cout<<sum<<endl;
        }
    }
    return 0;
}

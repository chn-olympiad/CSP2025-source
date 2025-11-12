#include<bits/stdc++.h>
using namespace std;
//豹2A7V == 豹2 + A7V
string din(int a,int b,int c){
    if(a>=b&&b>=c)
        return "abc";
    if(a>=c&&c>=b)
        return "acb";
    if(b>=a&&a>=c)
        return "bac";
    if(b>=c&&c>=a)
        return "bca";
    if(c>=b&&b>=a)
        return "cba";
    if(c>=a&&a>=b)
        return "cab";
}
  struct p{
    int a,b,c;
    int cha=0;
    };
    bool cmp(p x,p y){
        return x.cha<y.cha;
    }
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int T;
    cin>>T;
    while(T--){
    p q[100005];
        int n;
        cin>>n;
    for(int i=1;i<=n;i++)
        cin>>q[i].a>>q[i].b>>q[i].c;

    int suma=0,sumb=0,sumc=0;
    int sum=0;
    int sa[100005],sb[100005],sc[100005];
    for(int i=1;i<=n;i++){
        if(din(q[i].a,q[i].b,q[i].c)=="abc"){
            q[i].cha=q[i].a-q[i].b;

        }
        else if(din(q[i].a,q[i].b,q[i].c)=="acb"){
            q[i].cha=q[i].a-q[i].c;

        }else if(din(q[i].a,q[i].b,q[i].c)=="bac"){
            q[i].cha=q[i].b-q[i].a;

        }
        else if(din(q[i].a,q[i].b,q[i].c)=="bca"){
            q[i].cha=q[i].b-q[i].c;

        }
        else if(din(q[i].a,q[i].b,q[i].c)=="cab"){
            q[i].cha=q[i].c-q[i].a;

        }
        else if(din(q[i].a,q[i].b,q[i].c)=="cba"){
            q[i].cha=q[i].c-q[i].b;

        }

    }
    sort(q+1,q+1+n,cmp);
    for(int i=1;i<=n;i++){
         if(din(q[i].a,q[i].b,q[i].c)=="abc"){

            suma++;
            sa[suma]=i;
            sum+=q[i].a;
        }
        else if(din(q[i].a,q[i].b,q[i].c)=="acb"){

            suma++;
            sa[suma]=i;
             sum+=q[i].a;
        }else if(din(q[i].a,q[i].b,q[i].c)=="bac"){

            sumb++;
            sb[sumb]=i;
             sum+=q[i].b;
        }
        else if(din(q[i].a,q[i].b,q[i].c)=="bca"){

            sumb++;
            sb[sumb]=i;
             sum+=q[i].b;
        }
        else if(din(q[i].a,q[i].b,q[i].c)=="cab"){

            sumc++;
            sc[sumc]=i;
             sum+=q[i].c;
        }
        else if(din(q[i].a,q[i].b,q[i].c)=="cba"){

            sumc++;
            sc[sumc]=i;
             sum+=q[i].c;
        }

    }
    if(suma>n/2)
    {
        int k=suma-n/2;
        for(int i=1;i<=k;i++){
            sum-=q[sa[i]].cha;

        }
    }
    if(sumb>n/2)
    {
        int k=sumb-n/2;
        for(int i=1;i<=k;i++){
            sum-=q[sb[i]].cha;

        }
    }
   // cout<<sum<<endl;
    if(sumc>n/2)
    {
        int k=sumc-n/2;
       // cout<<sumc<<endl;
     //  for(int i=1;i<=sumc;i++)
           // cout<<sc[i]<<" "<<q[sc[i]].a<<" ";
        for(int i=1;i<=k;i++){
            sum-=q[sc[i]].cha;

        }
    }
    cout<<sum<<endl;

}
}


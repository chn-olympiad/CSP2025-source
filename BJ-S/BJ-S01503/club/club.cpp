#include <bits/stdc++.h>
using namespace std;
int t,n,sum,x,y,z,m,a,j=1;
struct abc{
    int man,bu;
}s[10],cha[200005];
bool cmp(abc x,abc y){
    return x.man<y.man;
}
bool r;
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>s[1].man>>s[2].man>>s[3].man;
            s[1].bu=1,s[2].bu=2,s[3].bu=3;
            sort(s+1,s+4,cmp);
            cha[i].man=s[3].man-s[2].man,cha[i].bu=s[3].bu;
            if(s[3].bu==1)x++;
            else if(s[3].bu==2)y++;
            else z++;
            sum+=s[3].man;
            if(x>n/2)r=1,m=x-n/2,a=1;
            if(y>n/2)r=1,m=y-n/2,a=2;
            if(z>n/2)r=1,m=z-n/2,a=3;
        }
        if(r==0)cout<<sum<<endl;
        else{
            sort(cha+1,cha+n+1,cmp);
            while(m>0){
                if(cha[j].bu==a)sum-=cha[j].man,m--;
                j++;
            }
            cout<<sum<<endl;
        }
        sum=r=x=y=z=0;j=1;
    }
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int a[500001];
int n,k,o=1,sum;
struct stu{
    int ll,rr,zz;
}b[500001];
bool cmp(stu c,stu d){
    return c.zz<=d.zz;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int l=1;l<=n;l++){
        for(int r=l;r<=n;r++){
            int q=0;
            for(int h=l;h<=r;h++){
                q^=a[h];

            }
            if(q==k){
                b[o].ll=l;b[o].rr=r;
                b[o].zz=r-l+1;
                o++;
            }
        }
    }
    sort(b+1,b+o,cmp);
    sum=o-1;
    for(int i=1;i<o;i++){
        for(int j=i+1;j<o;j++){
            if(((b[i].ll>=b[j].ll&&b[i].ll<=b[j].rr)||(b[i].rr>=b[j].ll&&b[i].rr<=b[j].rr))&&(b[i].ll!=-1&&b[i].rr!=-1&&b[j].ll!=-1&&b[j].rr!=-1)){
                sum--;
                b[j].ll=b[j].rr=-1;
            }
        }
    }
    cout<<sum;
    return 0;
}

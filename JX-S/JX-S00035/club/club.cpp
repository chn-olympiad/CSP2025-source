#include<bits/stdc++.h>
using namespace std;
struct stu{
int id,num;
};
stu a[100006],b[100006],c[100006],d[100006],z[100006],y[100006];
bool cmp(stu p,stu q){
if(p.num==q.num)
    return p.id<q.id;
return p.num<q.num;
}
int main(){
freopen("club.in","r",stdin);
freopen("club.out","w",stdout);
int t;
cin>>t;
for(int i=1;i<=t;i++){
    int n,e=100000,f=100000,g=100000,ans=100000,sum=0,ans2=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].num>>b[i].num>>c[i].num;
        a[i].id=i;
        b[i].id=i;
        c[i].id=i;
    }
    while(g>(n/2)&&e>(n/2)&&f>(n/2)){
            f=0; g=0; e=0;
            int i=0,j=0,h=0;
    for(int i=1;i<=n;i++){
        if(a[i].num>=b[i].num&&a[i].num>=c[i].num) {
                d[i].num=a[i].num; e++;
        }
        if(b[i].num>=a[i].num&&b[i].num>=c[i].num) {
                d[i].num=b[i].num; f++;
        }
        if(c[i].num>=b[i].num&&c[i].num>=a[i].num) {
                d[i].num=c[i].num; g++;
        }
    }
    for(int i=0;i<=n;i++){
         if(a[i].num<b[i].num){
        if(y[i].num<c[i].num){
            if(c[i].num<b[i].num) {
                    y[i].num=c[i].num;j++;
            }else {
                    y[i].num=b[i].num; i++;
            }
        } else {
            y[i].num=a[i].num;h++;
            }
    }else{
    if(y[i].num<c[i].num){
            if(c[i].num<a[i].num) {
                    y[i].num=c[i].num;j++;
            }else {
                    y[i].num=a[i].num;h++;
                    }
        } else{
            y[i].num=b[i].num; i++;
            }
    }
    }
    int m;
    if(e>=f&&e>=g) m=e;
    if(g>=f&&g>=e) m=g;
    if(f>=e&&f>=g) m=f;
    m=m-(n/2);
for(int i=1;i<=n;i++){
        z[i].num=d[i].num-y[i].num;
}
    sort(z+1,z+n+1,cmp);
  if(h>i&&h>j){
    a[z[1].id].num=0;
    d[z[1].id].num=y[z[i].id].num;
  }
  if(i>h&&i>j){
    b[z[1].id].num=0;
    d[z[1].id].num=y[z[i].id].num;
  }
  if(j>i&&j>h){
    c[z[1].id].num=0;
    d[z[1].id].num=y[z[i].id].num;
  }
}

if(g<=(n/2)&&e<=(n/2)&&f<=(n/2)){
        for(int i=1;i<=n;i++){
            ans+=d[i].num;
        }
        cout<<ans<<endl;
    }
}
return 0;
}


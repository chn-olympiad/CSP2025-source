#include <bits/stdc++.h>
using namespace std;
struct ABC{
    int id;
    int num;
    int student_id;
};
int t;
bool cmp(ABC x,ABC y){
    return x.num>y.num;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        int n;
        ABC a[100001],b[100001],c[100001],abc[300001];
        cin>>n;
        int mx=(n>>1);
        for(int i=1;i<=n;i++){
            cin>>a[i].num>>b[i].num>>c[i].num;
            a[i].student_id=i;
            b[i].student_id=i;
            c[i].student_id=i;
        }
        sort(a+1,a+n+1,cmp);
        sort(b+1,b+n+1,cmp);
        sort(c+1,c+n+1,cmp);
        for(int i=1;i<=n;i++){a[i].id=1;b[i].id=2;c[i].id=3;}
        for(int i=1;i<=n;i++) abc[i]=a[i];
        for(int i=n+1,j=1;i<=n*2,j<=n;i++,j++) abc[i]=b[j];
        for(int i=2*n+1,j=1;i<=n*3,j<=n;i++,j++) abc[i]=c[j];
        sort(abc+1,abc+n*3+1,cmp);
        int mx_a=0,mx_b=0,mx_c=0,cnt=0;
        int k[100001],flag=1;
        bool opflag=false;
        for(int i=1;i<=n;i++){
            if(mx_a==mx && abc[i].id==1) continue;
            if(mx_b==mx && abc[i].id==2) continue;
            if(mx_c==mx && abc[i].id==3) continue;
            if(abc[i].id==1) mx_a++;
            if(abc[i].id==2) mx_b++;
            if(abc[i].id==3) mx_c++;
            k[flag++]=abc[i].student_id;
            for(int j=1;j<=flag;j++){
                if(abc[i].student_id==k[j]){
                    opflag==true;
                    break;
                }
            }
            if(!opflag) cnt+=abc[i].num;
            if(opflag){
                opflag=false;
                continue;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

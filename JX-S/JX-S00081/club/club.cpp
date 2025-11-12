#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
struct oi{
    int c1,c2,c3;
}a[20005];
bool cmp1(oi a,oi b){
    return a.c1>b.c1;
}
bool cmp2(oi a,oi b){
    return a.c2>b.c2;
}
bool cmp3(oi a,oi b){
    return a.c3>b.c3;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t,n,maxs1=0,maxs2=0,maxs3=0,cnt=0,p1,p2,p3;
    bool flag;
    cin>>t;
    for(int i=0;i<t;i++){
        flag=true;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a[i].c1>>a[i].c2>>a[i].c3;
            if(maxs1<a[i].c1){
                maxs1=a[i].c1;
                p1=i;
            }
            if(maxs2<a[i].c2){
                maxs2=a[i].c2;
                p2=i;
            }
            if(maxs3<a[i].c3){
                maxs3=a[i].c3;
                p3=i;
            }
            if(a[i].c2!=0)flag=false;
        }
        if(flag){
            sort(a,a+n,cmp1);
            for(int i=0;i<n/2;i++){
                cnt+=a[i].c1;
            }
        }
        else if(n=2){
            if(maxs1>maxs2){
                if(maxs2>maxs3)cnt=maxs1+maxs2;
                else cnt=maxs1+maxs3;
            }
            else{
                if(maxs1>maxs3)cnt=maxs1+maxs2;
                else cnt=maxs2+maxs3;
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}

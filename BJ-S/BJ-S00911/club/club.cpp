#include<bits/stdc++.h>
using namespace std;
int n,t,ans,d[1000005],i1,i2,i3,ii1,ii2,ii3;
bool cmp(int a,int b){
    if(a>=b){
        return true;
    }else{
        return false;
    }
}
struct node{
    int m1,m2,m3;
}a[1000005],e[1000005];
int calculate(int h){
    int ax=max(a[h].m1,max(a[h].m2,a[h].m3));
    if(ax==a[h].m1){
        return 1;
    }else if(ax==a[h].m2){
        return 2;
    }else{
        return 3;
    }
}
void dp(){
    int s1=0,s2=0,s3=0;
    for(int i=1;i<=n;i++){
        if(a[i].m1>i1 && i!=ii1){
            i1=a[i].m1;
            ii1=i;
        }
        if(a[i].m2>i2 && i!=ii2){
            i2=a[i].m2;
            ii2=i;
        }
        if(a[i].m3>i3 && i!=ii3){
            i3=a[i].m3;
            ii3=i;
        }
    }
    if(s1>n/2){
        e[ii1].m1=e[ii2].m1=e[ii3].m1=-1;
    }
    if(s2>n/2){
        e[ii1].m2=e[ii2].m2=e[ii3].m2=-1;
    }
    if(s3>n/2){
        e[ii1].m3=e[ii2].m3=e[ii3].m3=-1;
    }
    if(calculate(ii1)==1){
        s1++;
        ans+=e[ii1].m1;
    }else if(calculate(ii1)==2){
        s2++;
        ans+=e[ii1].m2;
    }else if(calculate(ii1)==3){
        s3++;
        ans+=e[ii1].m3;
    }
    if(calculate(ii2)==1){
        s1++;
        ans+=e[ii2].m1;
    }else if(calculate(ii2)==2){
        s2++;
        ans+=e[ii2].m2;
    }else if(calculate(ii2)==3){
        s3++;
        ans+=e[ii2].m3;
    }
    if(calculate(ii3)==1){
        s1++;
        ans+=e[ii3].m1;
    }else if(calculate(ii3)==2){
        s2++;
        ans+=e[ii3].m2;
    }else if(calculate(ii3)==3){
        s3++;
        ans+=e[ii3].m3;
    }
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    for(int delta=1;delta<=t;delta++){
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i].m1>>a[i].m2>>a[i].m3;
            e[i].m1=a[i].m1;
            e[i].m2=a[i].m2;
            e[i].m3=a[i].m3;
        }
        dp();
        cout<<ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}

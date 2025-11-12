#include<bits/stdc++.h>
using namespace std;
struct node{
    int c1,c2,c3;
};
const int N=1e5+10;
int T,n,ans;
node a[N];
int c1[N],n1,c2[N],n2,c3[N],n3;
int t;
bool cmp(int x,int y){
    if(t==1) return max(a[x].c2,a[x].c3)-a[x].c1>max(a[y].c2,a[y].c3)-a[y].c1;
    if(t==2) return max(a[x].c1,a[x].c3)-a[x].c2>max(a[y].c1,a[y].c3)-a[y].c2;
    return max(a[x].c1,a[x].c2)-a[x].c3>max(a[y].c1,a[y].c2)-a[y].c3;
}
void Main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].c1>>a[i].c2>>a[i].c3;
        ans+=max({a[i].c1,a[i].c2,a[i].c3});
        if(a[i].c1>=a[i].c2&&a[i].c1>=a[i].c3) c1[++n1]=i;
        else if(a[i].c2>=a[i].c1&&a[i].c2>=a[i].c3) c2[++n2]=i;
        else if(a[i].c3>=a[i].c1&&a[i].c3>=a[i].c2) c3[++n3]=i;
    }
    if(n1>n/2){
        t=1;
        sort(c1+1,c1+n1+1,cmp);
        for(int i=1;i<=n1-n/2;i++)
            ans+=max(a[c1[i]].c2,a[c1[i]].c3)-a[c1[i]].c1;
    }
    else if(n2>n/2){
        t=2;
        sort(c2+1,c2+n2+1,cmp);
        for(int i=1;i<=n2-n/2;i++)
            ans+=max(a[c2[i]].c1,a[c2[i]].c3)-a[c2[i]].c2;
    }
    else{
        t=3;
        sort(c3+1,c3+n3+1,cmp);
        for(int i=1;i<=n3-n/2;i++)
            ans+=max(a[c3[i]].c1,a[c3[i]].c2)-a[c3[i]].c3;
    }
    cout<<ans<<endl;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>T;
    while(T--){
        ans=0;
        n1=n2=n3=0;
        t=0;
        Main();
    }
    return 0;
}
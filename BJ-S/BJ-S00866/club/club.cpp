#include<bits/stdc++.h>
using namespace std;
struct node{
    int m,ch,ch1;
    char abc;
}cl[100005];
bool cmp(node x,node y){
    return x.ch<y.ch;
}
bool cmp1(node x,node y){
    return x.ch1<y.ch1;
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    int t;
    cin>>t;
    while(t--){
        int n;
        long long cnt1=0,cnt2=0;
        cin>>n;
        int a[100005],b[100005],c[100005];
        int ca=0,cb=0,cc=0;
        for(int i=1;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            cl[i].m=max(a[i],max(b[i],c[i]));
            if(cl[i].m==a[i]){
                ca++;
                cl[i].ch=cl[i].m-max(b[i],c[i]);
                cl[i].ch1=abs(b[i]-c[i]);
                cl[i].abc='a';
            }
            else if(cl[i].m==b[i]){
                cb++;
                cl[i].ch=cl[i].m-max(a[i],c[i]);
                cl[i].ch1=abs(a[i]-c[i]);
                cl[i].abc='b';
            }
            else{
                cc++;
                cl[i].ch=cl[i].m-max(b[i],c[i]);
                cl[i].ch1=abs(b[i]-a[i]);
                cl[i].abc='c';
            }
        }
        if(max(ca,max(cb,cc))>n/2){
            sort(cl+1,cl+n+1,cmp);
            for(int i=1;i<=max(ca,max(cb,cc));i++){
                cnt1+=cl[i].ch;
                if(cl[i].abc=='a'){
                    ca--;
                    if(b[i]>c[i]) cb++;
                    else cc++;
                }
                else if(cl[i].abc=='b'){
                    cb--;
                    if(a[i]<c[i]) cc++;
                    else ca++;
                }
                else{
                    cc--;
                    if(a[i]<b[i]) cb++;
                    else ca++;
                }
            }
        }
        if(max(ca,max(cb,cc))>n/2){
            sort(cl+1,cl+n+1,cmp1);
            for(int i=1;i<=max(ca,max(cb,cc));i++){
                cnt2+=cl[i].ch1;
            }
        }
        long long ans=0;
        for(int i=1;i<=n;i++){
            ans+=cl[i].m;
        }
        cout<<ans-cnt1-cnt2;
    }
return 0;
}

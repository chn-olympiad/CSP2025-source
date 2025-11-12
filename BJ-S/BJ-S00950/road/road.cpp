#include<bits/stdc++.h>
using namespace std;
int n,m,k,cnt1,cnt2,cnt3;
int b[20][100010];
int col[100010];
struct node{
    int st,la,nm;
}a[1000000],c[1000000];
void merg(int l,int r){
    int mid=(l+r)/2;
    int ll=l;
    int rr=mid+1;
    int num=l;
    while(ll<=mid&&rr<=r){
        if(a[ll].nm<a[rr].nm){
            c[num].la=a[ll].la;
            c[num].st=a[ll].st;
            c[num].nm=a[ll].nm;
            num++;
            ll++;
        }else{
            c[num].la=a[rr].la;
            c[num].st=a[rr].st;
            c[num].nm=a[rr].nm;
            num++;
            rr++;
        }
    }
    while(ll<=mid){
        c[num].la=a[ll].la;
        c[num].st=a[ll].st;
        c[num].nm=a[ll].nm;
        num++;
        ll++;
    }
    while(rr<=r){
        c[num].la=a[rr].la;
        c[num].st=a[rr].st;
        c[num].nm=a[rr].nm;
        num++;
        rr++;
    }
    for(int i=l;i<=r;i++){
        a[i].la=c[i].la;
        a[i].st=c[i].st;
        a[i].nm=c[i].nm;
    }
    return;
}
void merge_sort(int l,int r){
    if(l==r)return;
    int mid=(l+r)/2;
    merge_sort(1,mid);
    merge_sort(mid+1,r);
    merg(l,r);
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> m >> k;
    cnt3=n;
    for(int i=1;i<=n;i++){
        cnt1++;
        int p,q,w;
        cin >> p >> q >> w;
        a[i].la=q;
        a[i].st=p;
        a[i].nm=w;
    }
    for(int i=1;i<=k;i++){
        cnt3++;
        int op;
        cin >> op;
        if(op==0){
            for(int j=1;j<=n;j++){
                cnt1++;
                int w;
                cin >> w;
                a[cnt1].st=cnt3;
                a[cnt1].la=j;
                a[cnt1].nm=w;
            }
        }else{
            cnt2++;
            for(int i=1;i<=n;i++){
                int j;
                cin >> j;
                b[cnt2][i]=j;
            }
        }
    }
    int ans=0;
    if(cnt2==0){
        int co=0;
        merge_sort(1,cnt1);
        for(int i=1;i<=cnt1;i++){
            co++;
            if(col[a[i].st]==col[a[i].la]&&col[a[i].st]!=0)continue;
            else{
                ans+=a[i].nm;
                if(col[a[i].st]==0&&col[a[i].la]==0){
                    col[a[i].st]=co;
                    col[a[i].la]=co;
                    continue;
                }else{
                    if(col[a[i].st]==0)col[a[i].st]=co;
                    if(col[a[i].la]==0)col[a[i].la]=co;
                    int coa=col[a[i].st];
                    int cob=col[a[i].la];
                    for(int j=1;j<=n+k;j++){
                        if(col[j]==coa||col[j]==cob)col[j]=co;
                    }
                }
            }
        }
    }
    cout << ans;
    return 0;
}

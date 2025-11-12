#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,n,cnt1,cnt2,cnt3,ans,a[100005],b[100005],c[100005];
priority_queue<pair<int,int> > qa0,qa1,qb0,qb1,qc0,qc1,qa,qb,qc;
inline void worka(int i){
    cnt1++;
    qa0.push(make_pair(c[i]-a[i],i));
    qa1.push(make_pair(b[i]-a[i],i));
}
inline void workb(int i){
    cnt2++;
    qb0.push(make_pair(a[i]-b[i],i));
    qb1.push(make_pair(c[i]-b[i],i));
}
inline void workc(int i){
    cnt3++;
    qc0.push(make_pair(b[i]-c[i],i));
    qc1.push(make_pair(a[i]-c[i],i));
}
void dfs(int i,int cnt1,int cnt2,int cnt3,int tot){
    if(i==n+1){
        ans=max(ans,tot);
        return;
    }
    if(cnt1!=(n>>1)) dfs(i+1,cnt1+1,cnt2,cnt3,tot+a[i]);
    if(cnt2!=(n>>1)) dfs(i+1,cnt1,cnt2+1,cnt3,tot+b[i]);
    if(cnt3!=(n>>1)) dfs(i+1,cnt1,cnt2,cnt3+1,tot+c[i]);
}
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        if(n<=10){
            for(int i=1;i<=n;i++) cin>>a[i]>>b[i]>>c[i];
            dfs(1,0,0,0,0);
            cout<<ans<<'\n';
            ans=0;
        }
//        else if(n<=30){
//        for(int i=1,tmp;i<=n;i++){
//            cin>>a[i]>>b[i]>>c[i];
//            int maxx=max(a[i],max(b[i],c[i]));
//            ans+=maxx;
//            if(maxx==a[i]){
//                worka(i);
//                if(cnt1<=(n>>1)) continue;
//                cnt1--;
//                if(cnt2==(n>>1)||qa0.top().first>qa1.top().first){
//                    ans+=qa0.top().first,workc(qa0.top().second);
//                    qa0.pop();
//                }else{
//                    ans+=qa1.top().first,workb(qa1.top().second);
//                    qa1.pop();
//                }
//            }else if(maxx==b[i]){
//                workb(i);
//                if(cnt2<=(n>>1)) continue;
//                cnt2--;
//                if(cnt3==(n>>1)||qb0.top().first>qb1.top().first){
//                    ans+=qb0.top().first,worka(qb0.top().second);
//                    qb0.pop();
//                }else{
//                    ans+=qb1.top().first,workc(qb1.top().second);
//                    qb1.pop();
//                }
//            }else{
//                workc(i);
//                if(cnt3<=(n>>1)) continue;
//                cnt3--;
//                if(cnt1==(n>>1)||qc0.top().first>qc1.top().first){
//                    ans+=qc0.top().first,workb(qc0.top().second);
//                    qc0.pop();
//                }else{
//                    ans+=qc1.top().first,worka(qc1.top().second);
//                    qc1.pop();
//                }
//            }
//        }
//        cout<<ans<<'\n';
//        while(!qa0.empty()) qa0.pop();
//        while(!qa1.empty()) qa1.pop();
//        while(!qb0.empty()) qb0.pop();
//        while(!qb1.empty()) qb1.pop();
//        while(!qc0.empty()) qc0.pop();
//        while(!qc1.empty()) qc1.pop();
//        cnt1=cnt2=cnt3=ans=0;
//        }
        else{
        for(int i=1,tmp,la;i<=n;i++){
            cin>>a[i]>>b[i]>>c[i];
            int maxx=max(a[i],max(b[i],c[i]));
            if(maxx==a[i]){
                qa.push(make_pair(b[i]-a[i],i));
                cnt1++,ans+=a[i];
                if(cnt1==(n>>1)+1){
                    la=qa.top().first,tmp=qa.top().second;
                    ans+=la;
                    qa.pop();
                    cnt2++,cnt1--;
                    qb.push(make_pair(c[tmp]-b[tmp],tmp));
                    if(cnt2==(n>>1)+1){
                        tmp=qb.top().second,ans+=c[tmp]-a[tmp]-la;
                        qb.pop();
                        cnt3++,cnt2--;
                        qc.push(make_pair(a[tmp]-c[tmp],tmp));
                    }
                }
            }else if(maxx==b[i]){
                qb.push(make_pair(c[i]-b[i],i));
                cnt2++,ans+=b[i];
                if(cnt2==(n>>1)+1){
                    la=qb.top().first,tmp=qb.top().second;
                    ans+=la;
                    qb.pop();
                    cnt3++,cnt2--;
                    qc.push(make_pair(a[tmp]-c[tmp],tmp));
                    if(cnt3==(n>>1)+1){
                        tmp=qc.top().second,ans+=a[tmp]-b[tmp]-la;
                        qc.pop();
                        cnt1++,cnt3--;
                        qa.push(make_pair(b[tmp]-a[tmp],tmp));
                    }
                }
            }else{
                qc.push(make_pair(a[i]-c[i],i));
                cnt3++,ans+=c[i];
                if(cnt3==(n>>1)+1){
                    la=qc.top().first,tmp=qc.top().second;
                    ans+=la;
                    qc.pop();
                    cnt1++,cnt3--;
                    qa.push(make_pair(b[tmp]-a[tmp],tmp));
                    if(cnt1==(n>>1)+1){
                        tmp=qa.top().second,ans+=b[tmp]-c[tmp]-la;
                        qa.pop();
                        cnt2++,cnt1--;
                        qb.push(make_pair(c[tmp]-b[tmp],tmp));
                    }
                }
            }
        }
        cout<<ans<<'\n';
        while(!qa.empty()) qa.pop();
        while(!qb.empty()) qb.pop();
        while(!qc.empty()) qc.pop();
        cnt1=cnt2=cnt3=ans=0;
        }
    }
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+9;
int _,n;
struct node {
    int a,b,c;
} no[N];
int q,w,e;

bool cmp(node x,node y){
    if(x.a!=y.a){ return x.a>y.a; }
    return x.b>y.b;
}

signed main() {
        freopen("club.in","r",stdin);
        freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>_;
    while(_--) {
        vector<int > a,b,c;
        int ans=0;
        cin>>n;
        bool __=false,___=false,____=false;
        for(int i=0; i<n; i++) {
            cin>>q>>w>>e;
            if(w)__=true;
            if(e)___=true;
            if(q)____=true;
            a.push_back(q);
            b.push_back(w);
            c.push_back(e);
            no[i].a=q;
            no[i].b=w;
            no[i].c=e;
        }
        if(n==2) {
            ans=max(ans,a[0]+b[1]);
            ans=max(ans,a[0]+b[2]);
            ans=max(ans,a[0]+c[1]);
            ans=max(ans,a[0]+c[2]);

            ans=max(ans,a[1]+c[0]);
            ans=max(ans,a[1]+c[2]);
            ans=max(ans,a[1]+b[0]);
            ans=max(ans,a[1]+b[2]);

            ans=max(ans,a[2]+b[0]);
            ans=max(ans,a[2]+b[1]);
            ans=max(ans,a[2]+c[1]);
            ans=max(ans,a[2]+c[0]);
            cout<<ans<<endl;
            continue;
        }




        if(____&&__&&!___) {
            int cnt1=0,cnt2=0,cc=n/2;
            int ret=0;bool f=true,f1=true;
            sort(no,no+n,cmp);
            for(int i=0;i<n;i++){
                if(!f){ ret+=no[i].b;continue;}
                if(!f1){ ret+=no[i].a;continue;}
                if( no[i].a>no[i].b ){ if(cnt1==cc){ ret+=no[i].b; f=false;continue; } ret+=no[i].a;  }
                if(no[i].a<=no[i].b){ if(cnt2==cc){ ret+=no[i].a; f1=false;continue; } ret+=no[i].b;  }
            }
            cout<<ret<<endl;return 0;
        }






















//============================================================
        if(____&&!__&&!___) { //spc for 12
            sort(a.begin(),a.end());
            reverse(a.begin(),a.end());
            for(int i=0; i<n/2; i++) {
                ans+=a[i];
            }
            cout<<ans<<endl;
            continue;
        } else if(!____&&__&&!___) {
            sort(b.begin(),b.end());
            reverse(b.begin(),b.end());
            for(int i=0; i<n/2; i++) {
                ans+=b[i];
            }
            cout<<ans<<endl;
            continue;
        } else if(!____&&!__&&___) {
            sort(c.begin(),c.end());
            reverse(c.begin(),c.end());
            for(int i=0; i<n/2; i++) {
                ans+=c[i];
            }
            cout<<ans<<endl;
            continue;
        }
//============================================================
        else { //normal
            int cnt1=0,cnt2=0,cnt3=0,cc=n/2;
            for(int i=0; i<n; i++) {
                int t=max( no[i].a,max(no[i].b,no[i].c) );
                if(t==no[i].a) {
                    if(cnt1<cc) {
                        cnt1++;
                        ans+=t;
                        continue;
                    }
                    if(cnt2<cc) {
                        cnt2++;
                        ans+=t;
                        continue;
                    }
                    if(cnt3<cc) {
                        cnt3++;
                        ans+=t;
                        continue;
                    }
                }
                if(t==no[i].b) {
                    if(cnt2<cc) {
                        cnt2++;
                        ans+=t;
                        continue;
                    }
                    if(cnt1<cc) {
                        cnt1++;
                        ans+=t;
                        continue;
                    }
                    if(cnt3<cc) {
                        cnt3++;
                        ans+=t;
                        continue;
                    }
                }
                if(t==no[i].c) {
                    if(cnt3<cc) {
                        cnt3++;
                        ans+=t;
                        continue;
                    }
                    if(cnt1<cc) {
                        cnt1++;
                        ans+=t;
                        continue;
                    }
                    if(cnt2<cc) {
                        cnt2++;
                        ans+=t;
                        continue;
                    }

                }
            }

        }
        //cout<<"\n\n";
        cout<<ans<<"\n";
        //cout<<"\n\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//Ren5Jie4Di4Ling5%


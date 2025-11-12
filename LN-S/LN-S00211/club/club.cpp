#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e5+5;
struct node{
    int a,b,c;
}p[N];
bool cmpa(node p,node q)
{
    if (p.a!=q.a)return p.a>q.a; // 之前的尽量大，后面的尽量小
    if (p.b!=q.b)return p.b<q.b;
    if (p.c!=q.c)return p.c<q.c;
}
bool cmpb(node p,node q)
{
    if (p.b!=q.b)return p.b>q.b;
    if (p.a!=q.a)return p.a<q.a;
    if (p.c!=q.c)return p.c<q.c;
}
bool cmpc(node p,node q)
{
    if (p.c!=q.c)return p.c>q.c;
    if (p.b!=q.b)return p.b<q.b;
    if (p.a!=q.a)return p.a<q.a;
}
ll maxn=-1;
int main()
{
    freopen("club.in", "r", stdin);
    freopen("club.out","w",stdout);
    int t;
    cin >> t;
    while(t--){
        int n;
        int two_0=0; // the same position is 0 all
        int pos=-1; // the anti-zero position
        cin >> n;
        for (int i=0;i<n;i++){
            int zero=0;
            cin >>p[i].a>>p[i].b>>p[i].c;
            if(p[i].a==0)zero++;else pos=0;
            if(p[i].b==0)zero++;else pos=1;
            if(p[i].c==0)zero++;else pos=2;
            if (zero<2)two_0=-1;
        }
        if (n==2){
            cout << max({p[0].a+p[1].b,p[0].a+p[1].c,p[0].b+p[1].a,p[0].b+p[1].c,p[0].c+p[1].a,p[0].c+p[1].b})<<endl;
            continue;
        }
        else if (n==10){
            ll ans=0;
            int ca=0,cb=0,cc=0;
            for (int i=0;i<3;i++){for(int j=0;j<3;j++){for (int k=0;k<3;k++){for (int q=0;q<3;q++){for(int d=0;d<3;d++){for(int e=0;e<3;e++){for(int f=0;f<3;f++){for(int g=0;g<3;g++){for(int h=0;h<3;h++){for(int l=0;l<3;l++){
                ans=0;
                if(i==0){ca++,ans+=p[0].a;}else if(i==1){cb++,ans+=p[0].b;}else {cc++,ans+=p[0].c;}
                if(j==0){ca++,ans+=p[1].a;}else if(j==1){cb++,ans+=p[1].b;}else {cc++,ans+=p[1].c;}
                if(k==0){ca++,ans+=p[2].a;}else if(k==1){cb++,ans+=p[2].b;}else {cc++,ans+=p[2].c;}
                if(q==0){ca++,ans+=p[3].a;}else if(q==1){cb++,ans+=p[3].b;}else {cc++,ans+=p[3].c;}
                if(d==0){ca++,ans+=p[4].a;}else if(d==1){cb++,ans+=p[4].b;}else {cc++,ans+=p[4].c;}
                if(e==0){ca++,ans+=p[5].a;}else if(e==1){cb++,ans+=p[5].b;}else {cc++,ans+=p[5].c;}
                if(f==0){ca++,ans+=p[6].a;}else if(f==1){cb++,ans+=p[6].b;}else {cc++,ans+=p[6].c;}
                if(g==0){ca++,ans+=p[7].a;}else if(g==1){cb++,ans+=p[7].b;}else {cc++,ans+=p[7].c;}
                if(h==0){ca++,ans+=p[8].a;}else if(h==1){cb++,ans+=p[8].b;}else {cc++,ans+=p[8].c;}
                if(l==0){ca++,ans+=p[9].a;}else if(l==1){cb++,ans+=p[9].b;}else {cc++,ans+=p[9].c;}
                if(ca<6&&cb<6&&cc<6){if(ans>maxn)maxn=ans;}
        }}}}}}}}}}
        cout << ans<<endl;
        continue;
        }



        else if (two_0==0){
            if (pos==0){ // a
                ll ans=0;
                sort(p,p+n,cmpa);
                for (int i=0;i<n/2;i++)ans+=p[i].a;
                cout << ans << endl;
            }
            if (pos==1){ // b
                ll ans=0;
                sort(p,p+n,cmpb);
                for (int i=0;i<n/2;i++)ans+=p[i].b;
                cout << ans << endl;
            }
            if (pos==2){ // c
                ll ans=0;
                sort(p,p+n,cmpc);
                for (int i=0;i<n/2;i++)ans+=p[i].c;
                cout << ans << endl;
            }
            continue;
        }

        ll ans=0;
        int cnta=0,cntb=0,cntc=0;  // to judge if it has > n/2
        int cnt=0;  // total count of the operation
        while (cnt<n-1){
            int maxa=-1,maxb=-1,maxc=-1;
            cnt=cnta+cntb+cntc;  // total count of the operation
            if(cnta<=n/2){
                sort(p+cnt,p+n,cmpa);
                /*for (int i=cnt;i<n;i++){
                    cout << p[i].a << " " << p[i].b << " "<<p[i].c << endl;
                }*/
                maxa=p[cnta].a;
                //cout << maxa<< "\n\n";
            }

            if (cntb<=n/2){
                sort(p+cnt,p+n,cmpb);
                /*for (int i=cnt;i<n;i++){
                    cout << p[i].a << " " << p[i].b << " "<<p[i].c << endl;
                }*/
                maxb=p[cntb].b;
                //cout << maxb<< "\n\n";
            }

            if(cntc<=n/2){
                sort(p+cnt,p+n,cmpc);
                /*for (int i=cnt;i<n;i++){
                    cout << p[i].a << " " << p[i].b << " "<<p[i].c << endl;
                }*/
                maxc=p[cntc].c;
                //cout << maxc<< "\n\n";
            }

            int qwq=max({maxa,maxb,maxc});
            if (maxa==qwq){
                cnta++;
                ans+=maxa;
            }
            else if (maxb==qwq){
                cntb++;
                ans+=maxb;
            }
            else if (maxc==qwq){
                cntc++;
                ans+=maxc;
            }
            //cout << "qwq     ans\n";
            //cout << qwq << " " << ans << "\n\n";

        }
        cout << ans << endl;

    }

    return 0;
}

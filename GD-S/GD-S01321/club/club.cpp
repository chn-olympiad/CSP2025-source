#include<bits/stdc++.h>

typedef int IT;
typedef long long LL;
typedef __int128 int128;
typedef double DB;

#define pb push_back
#define fst first
#define sec second
#define psh push
#define PII pair<IT,IT>
#define PLI pair<LL,IT>
#define lowbit(x) ((x)&(-x))

using namespace std;

const int N=1e5+10;

int n;
int a[N][4];

int ans;
namespace sub1{
    bool check(){
        for(int i=1;i<=n;i++){
            if(!(a[i][2]==a[i][3] && a[i][3]==0)) return 0;
        }
        return 1;
    }

    void solve(){
        vector<int>g;g.clear();// g.pb(0);
        for(int i=1;i<=n;i++){
            g.pb(a[i][1]);
        }
        sort(g.begin(),g.end(),greater<int>());

        for(int i=0;i<n/2;i++) ans+=g[i];
        printf("%d\n",ans);
        return;
    }
};

namespace sub2{
    int sum;
    int cnt[4];
    int hf;
    void dfs(int x){
        if(x>n){
            ans=max(ans,sum);
            return;
        }
        if(cnt[1]<hf){
            cnt[1]++;
            sum+=a[x][1];
            dfs(x+1);
            sum-=a[x][1];
            cnt[1]--;
        }
        if(cnt[2]<hf){
            cnt[2]++;
            sum+=a[x][2];
            dfs(x+1);
            sum-=a[x][2];
            cnt[2]--;
        }
        if(cnt[3]<hf){
            cnt[3]++;
            sum+=a[x][3];
            dfs(x+1);
            sum-=a[x][3];
            cnt[3]--;
        }
        return;
    }
    void solve(){
        hf=n/2;
        for(int i=1;i<=3;i++) cnt[i]=0;
        sum=0;
        dfs(1);

        printf("%d\n",ans);
        return;
    }
};

void sl_reset();
void solve(){
    sl_reset();

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
    }

    if(sub1::check()){
        sub1::solve();
        return;
    }
    else if(n<=10){
        sub2::solve();
        return;
    }
    /*3
4
3 0 0
7 0 0
5 0 0
1 0 0
4
1 0 0
1 0 0
1 0 0
1 0 0
4
12 0 0
3 0 0
5 0 0
1 0 0

    */
    return;
}
void sl_reset(){
    ans=0;
    return;
}

int main(){
	freopen("club.in","r",stdin);
	// freopen("club3.in","r",stdin);
	freopen("club.out","w",stdout);
	
    int T=1;
    scanf("%d",&T);
    while(T--){
        solve();
    }
	return 0;
}
/*
C:\Users\Administrator>gcc --version
gcc (MinGW-W64 x86_64-msvcrt-posix-seh, built by Brecht Sanders, r8) 13.2.0
Copyright (C) 2023 Free Software Foundation, Inc.
This is free software; see the source for copying conditions.  There is NO
warranty; not even for MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
*/
// 3.cpp
// 2.cpp
/*
#include<bits/stdc++.h>

typedef int IT;
typedef long long LL;
typedef __int128 int128;
typedef double DB;

#define pb push_back
#define fst first
#define sec second
#define psh push
#define PII pair<IT,IT>
#define PLI pair<LL,IT>
#define lowbit(x) ((x)&(-x))

using namespace std;

const int N=1e5+10;

int n;
int a[N][4];

set<PII>st;
set<PII>:: iterator it;
int val[4];

priority_queue<PII>q[4];
int cnt[4];
int ans1,ans2,ans3,ans;
bool choos[N];

void sl_reset();
void solve(){
    sl_reset();

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
        q[1].psh({a[i][1],i});
        q[2].psh({a[i][2],i});
        q[3].psh({a[i][3],i});
    }

    // 1
    st.insert({3,1}),st.insert({2,2}),st.insert({1,3});
    val[1]=3,val[2]=2,val[3]=1;
    
    for(int i=1;i<=n;i++){
        int mx=0;
        PII pp={0,0};
        int id=0;
        for(it=st.begin();it!=st.end();it++){
            int bh=(*it).sec;
            PII p=q[bh].top();
            if(choos[p.sec]){
                q[bh].pop();
                continue;
            }
            if(p.fst>pp.fst) pp={p.fst,bh},id=p.sec;
        }
        ans1+=pp.fst;
        cnt[pp.sec]++;
        q[pp.sec].pop();
        choos[id]=1;
        if(cnt[pp.sec]==(n/2) || q[pp.sec].empty()) st.erase({val[pp.sec],pp.sec});
    }
    for(int i=1;i<=3;i++){
        if(st.find({val[i],i})!=st.end()) st.erase({val[i],i});
    }
    ans=max(ans,ans1);
    for(int i=1;i<=3;i++){
        while(!q[i].empty()) q[i].pop();
    }
    st.clear();
    for(int i=1;i<=3;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) choos[i]=0;
    
    // 2
    for(int i=1;i<=n;i++){
        q[1].psh({a[i][1],i});
        q[2].psh({a[i][2],i});
        q[3].psh({a[i][3],i});
    }
    st.insert({1,1}),st.insert({3,2}),st.insert({2,3});
    val[1]=1,val[2]=3,val[3]=2;
    
    for(int i=1;i<=n;i++){
        int mx=0;
        PII pp={0,0};
        int id=0;
        for(it=st.begin();it!=st.end();it++){
            int bh=(*it).sec;
            PII p=q[bh].top();
            if(choos[p.sec]){
                q[bh].pop();
                continue;
            }
            if(p.fst>pp.fst) pp={p.fst,bh},id=p.sec;
        }
        ans2+=pp.fst;
        cnt[pp.sec]++;
        q[pp.sec].pop();
        choos[id]=1;
        if(cnt[pp.sec]==(n/2) || q[pp.sec].empty()) st.erase({val[pp.sec],pp.sec});
    }
    for(int i=1;i<=3;i++){
        if(st.find({val[i],i})!=st.end()) st.erase({val[i],i});
    }
    ans=max(ans,ans2);
    for(int i=1;i<=3;i++){
        while(!q[i].empty()) q[i].pop();
    }
    st.clear();
    for(int i=1;i<=3;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) choos[i]=0;
    
    // 3
    for(int i=1;i<=n;i++){
        q[1].psh({a[i][1],i});
        q[2].psh({a[i][2],i});
        q[3].psh({a[i][3],i});
    }
    st.insert({1,1}),st.insert({2,2}),st.insert({3,3});
    val[1]=1,val[2]=2,val[3]=3;
    
    for(int i=1;i<=n;i++){
        int mx=0;
        PII pp={0,0};
        int id=0;
        for(it=st.begin();it!=st.end();it++){
            int bh=(*it).sec;
            PII p=q[bh].top();
            if(choos[p.sec]){
                q[bh].pop();
                continue;
            }
            if(p.fst>pp.fst) pp={p.fst,bh},id=p.sec;
        }
        ans3+=pp.fst;
        cnt[pp.sec]++;
        q[pp.sec].pop();
        choos[id]=1;
        if(cnt[pp.sec]==(n/2) || q[pp.sec].empty()) st.erase({val[pp.sec],pp.sec});
    }
    for(int i=1;i<=3;i++){
        if(st.find({val[i],i})!=st.end()) st.erase({val[i],i});
    }
    ans=max(ans,ans3);
    for(int i=1;i<=3;i++){
        while(!q[i].empty()) q[i].pop();
    }
    st.clear();
    for(int i=1;i<=3;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) choos[i]=0;

    printf("%d\n",ans);
    return;
}
void sl_reset(){
    ans=0;
    ans1=ans2=ans3=0;
    for(int i=1;i<=3;i++){
        while(!q[i].empty()) q[i].pop();
    }

    // for(int i=1;i<=3;i++)
    //     if(st.find(i)!=st.end()) st.erase(i);
    st.clear();
    
    for(int i=1;i<=3;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) choos[i]=0;
    return;
}

int main(){
	// freopen("club.in","r",stdin);
	// freopen("club1.in","r",stdin);
	// freopen("club.out","w",stdout);
	
    int T=1;
    scanf("%d",&T);
    while(T--){
        solve();
    }
	return 0;
}
*/
// (yuan)
/*
#include<bits/stdc++.h>

typedef int IT;
typedef long long LL;
typedef __int128 int128;
typedef double DB;

#define pb push_back
#define fst first
#define sec second
#define psh push
#define PII pair<IT,IT>
#define PLI pair<LL,IT>
#define lowbit(x) ((x)&(-x))

using namespace std;

const int N=1e5+10;

int n;
int a[N][4];

set<int>st;
set<int>:: iterator it;

priority_queue<PII>q[4];
int cnt[4];
int ans;
bool choos[N];

void sl_reset();
void solve(){
    sl_reset();

    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d %d",&a[i][1],&a[i][2],&a[i][3]);
        q[1].psh({a[i][1],i});
        q[2].psh({a[i][2],i});
        q[3].psh({a[i][3],i});
    }

    st.insert(1),st.insert(2),st.insert(3);
    
    for(int i=1;i<=n;i++){
        int mx=0;
        PII pp={0,0};
        int id=0;
        for(it=st.begin();it!=st.end();it++){
            PII p=q[*it].top();
            if(choos[p.sec]){
                q[*it].pop();
                continue;
            }
            if(p.fst>pp.fst) pp={p.fst,*it},id=p.sec;
        }
        ans+=pp.fst;
        cnt[pp.sec]++;
        q[pp.sec].pop();
        choos[id]=1;
        if(cnt[pp.sec]==(n/2) || q[pp.sec].empty()) st.erase(pp.sec);
    }

    printf("%d\n",ans);
    return;
}
void sl_reset(){
    ans=0;
    for(int i=1;i<=3;i++){
        while(!q[i].empty()) q[i].pop();
    }

    // for(int i=1;i<=3;i++)
    //     if(st.find(i)!=st.end()) st.erase(i);
    st.clear();
    
    for(int i=1;i<=3;i++) cnt[i]=0;
    for(int i=1;i<=n;i++) choos[i]=0;
    return;
}

int main(){
	// freopen("club.in","r",stdin);
	// freopen("club1.in","r",stdin);
	// freopen("club.out","w",stdout);
	
    int T=1;
    scanf("%d",&T);
    while(T--){
        solve();
    }
	return 0;
}
*/
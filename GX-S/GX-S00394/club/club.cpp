#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
#define For(x,l,r) for(ll x=l;x<=r;++x)
#define Rof(x,l,r) for(ll x=r;x>=l;--x)
#define pb push_back

const int N = 1e5+5;

int n;
int a[5][N];
int cl[N];
int s[4];
typedef pair<int,int> pii;
priority_queue<pii> ab,ac,ba,bc,ca,cb;
void push(int x){
    ab.push({a[2][x]-a[1][x],x});
    ac.push({a[3][x]-a[1][x],x});
    ba.push({a[1][x]-a[2][x],x});
    bc.push({a[3][x]-a[2][x],x});
    ca.push({a[1][x]-a[3][x],x});
    cb.push({a[2][x]-a[3][x],x});
}
void clean(){
    while(!ab.empty()) ab.pop();
    while(!ac.empty()) ac.pop();
    while(!ba.empty()) ba.pop();
    while(!bc.empty()) bc.pop();
    while(!ca.empty()) ca.pop();
    while(!cb.empty()) cb.pop();
    ab.push({-1e9,0});ac.push({-1e9,0});ba.push({-1e9,0});
    bc.push({-1e9,0});ca.push({-1e9,0});cb.push({-1e9,0});
}
void pop(){
    while(ab.size()>1&&cl[ab.top().second]!=1) ab.pop();
    while(ac.size()>1&&cl[ac.top().second]!=1) ac.pop();
    while(ba.size()>1&&cl[ba.top().second]!=2) ba.pop();
    while(bc.size()>1&&cl[bc.top().second]!=2) bc.pop();
    while(ca.size()>1&&cl[ca.top().second]!=3) ca.pop();
    while(cb.size()>1&&cl[cb.top().second]!=3) cb.pop();
}
ll ans;

void solve(){
    cin>>n;
    int nn=n/2;
    ans=0;
    s[1]=s[2]=s[3]=0;
    For(i,1,n) For(j,1,3) cin>>a[j][i];
    For(i,1,n) cl[i]=0;
    clean();
    For(i,1,n){
        pop();
        vector<pii> all;
        if(s[1]<nn){//1 a
            all.pb({a[1][i],1});
        }
        else{
            all.pb({a[1][i]+ac.top().first,4});
            all.pb({a[1][i]+ab.top().first,5});
            all.pb({a[1][i]+ab.top().first+bc.top().first,10});
            all.pb({a[1][i]+ac.top().first+cb.top().first,11});
        }
        if(s[2]<nn){//2 b
            all.pb({a[2][i],2});
        }
        else{
            all.pb({a[2][i]+ba.top().first,6});
            all.pb({a[2][i]+bc.top().first,7});
            all.pb({a[2][i]+bc.top().first+ca.top().first,12});
            all.pb({a[2][i]+ba.top().first+ac.top().first,13});
        }
        if(s[3]<nn){//3 c
            all.pb({a[3][i],3});
        }
        else{
            all.pb({a[3][i]+cb.top().first,8});
            all.pb({a[3][i]+ca.top().first,9});
            all.pb({a[3][i]+ca.top().first+ab.top().first,14});
            all.pb({a[3][i]+cb.top().first+ba.top().first,15});
        }
        
        sort(all.begin(),all.end());
        reverse(all.begin(),all.end());

        ans+=all[0].first;
        int op=all[0].second;
        push(i);
        if(op==1){
            cl[i]=1;
            s[1]++;
        }
        else if(op==2){
            cl[i]=2;
            s[2]++;
        }
        else if(op==3){
            cl[i]=3;
            s[3]++;
        }
        else if(op==4){
            cl[i]=1;
            cl[ac.top().second]=3;
            push(ac.top().second);
            s[3]++;
        }
        else if(op==5){
            cl[i]=1;
            cl[ab.top().second]=2;
            push(ab.top().second);
            s[2]++;
        }
        else if(op==6){
            cl[i]=2;
            cl[ba.top().second]=1;
            push(ba.top().second);
            s[1]++;
        }
        else if(op==7){
            cl[i]=2;
            cl[bc.top().second]=3;
            push(bc.top().second);
            s[3]++;
        }
        else if(op==8){
            cl[i]=3;
            cl[cb.top().second]=2;
            push(cb.top().second);
            s[2]++;
        }
        else if(op==9){
            cl[i]=3;
            cl[ca.top().second]=1;
            push(ca.top().second);
            s[1]++;
        }
        else if(op==10){
            cl[i]=1;
            cl[ab.top().second]=2;
            cl[bc.top().second]=3;
            push(ab.top().second);
            push(bc.top().second);
            s[3]++;
        }
        else if(op==11){
            cl[i]=1;
            cl[ac.top().second]=3;
            cl[cb.top().second]=2;
            push(ac.top().second);
            push(cb.top().second);
            s[2]++;
        }
        else if(op==12){
            cl[i]=2;
            cl[bc.top().second]=3;
            cl[ca.top().second]=1;
            push(bc.top().second);
            push(ca.top().second);
            s[1]++;
        }
        else if(op==13){
            cl[i]=2;
            cl[ba.top().second]=1;
            cl[ac.top().second]=3;
            push(ba.top().second);
            push(ac.top().second);
            s[3]++;
        }
        else if(op==14){
            cl[i]=3;
            cl[ca.top().second]=1;
            cl[ab.top().second]=2;
            push(ca.top().second);
            push(ab.top().second);
            s[2]++;
        }
        else if(op==15){
            cl[i]=3;
            cl[cb.top().second]=2;
            cl[ba.top().second]=1;
            push(cb.top().second);
            push(ba.top().second);
            s[1]++;
        }
    }
    cout<<ans<<'\n';
}

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);cin.tie(0);

    int T=1;
    cin>>T;
    while(T--){
        solve();
    }

    return 0;
}
/*
1s
512

eazy back-way greedy
*/
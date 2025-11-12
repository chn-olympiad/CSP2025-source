#include<bits/stdc++.h>
using namespace std;
constexpr int N=505,p=998244353,debug=0;
int n,m,a[N],b[N];
long long fac[N],ans;
char s[N];
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>m>>(s+1);
    fac[0]=1;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        fac[i]=fac[i-1]*i%p;
    }
    if(m==n){
        for(int i=1;i<=n;i++){
            if(a[i]==0||s[i]==0){
                cout<<0;
                return 0;
            }
        }
        cout<<fac[n];
        return 0;
    }
    if(m==1){
            int cnt=0;
        sort(a+1,a+1+n);
        for(int i=1;i<=n;i++){
            if(a[i]>=i)++ans;
    if(s[i]==0)++cnt;
        }
        if(ans>cnt){
            cout<<fac[n];
            return 0;
        }
    }
    for(int i=1;i<=n;i++)b[i]=i;
    for(int sss=3000000;sss;--sss){
        int cnt=0;
        for(int i=1;i<=n;i++){
            if(i-cnt-1>=a[b[i]]||s[i]=='0')continue;
            if(++cnt>=m){
                ++ans;
                if(ans>=p)ans-=p;
                break;
            }
        }
        if(!next_permutation(b+1,b+1+n))break;
    }
    cout<<ans;
    if(debug){
        cout<<"我常常追忆过去。\n";
        cout<<"生命瞬间定格在脑海。我将背后的时间裁剪、折叠、蜷曲，揉捻成天上朵朵白云。\n";
        cout<<"云朵之间亦有分别：积云厚重，而卷云飘渺。生命里震撼的场景掠过我的思绪便一生无法忘怀，而更为普通平常的记忆在时间的冲刷下只留下些许残骸。";
        cout<<"追忆宛如入梦，太过清楚则无法愉悦自己的幻想，过分模糊却又坠入虚无。只有薄雾间的山水，面纱下的好，那恰到好处的朦胧，才能满足我对美的苛求。\n";
        cout<<"追忆总在不经意间将我裹进泛黄的纸页里。分别又重聚的朋友，推倒又重建的街道，种种线索协助着我从一个具体的时刻出发沿时间的河逆流而上。";
        cout<<"曾经的日子无法重来，我只不过是一个过客。但我仍然渴望在每一次追忆之旅中留下闲暇时间，在一个场景前驻足，在岁月的朦胧里瞭望过去的自己，感受尽可能多的甜蜜。";
        cout<<"美好的时光曾流过我的身体，我便心满意足。\n";
        cout<<"过去已经凝固，我带着回忆向前，只是时常疏于保管，回忆也在改变着各自的形态。这给我的追忆旅程带来些许挑战。\n";
        cout<<"我该在哪里停留？我问我自己。\n";
    }
    return 0;
}

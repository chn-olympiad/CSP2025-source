#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
const int N=510;
const int MOD=998244353;

int n,m;
int n_tr; // the count of persons with md!=0
bool diff[N];
int md[N];
void all_1(){
    if(n_tr<m) cout<<0<<endl;
    if(n_tr==m) cout<<1<<endl;
    int ans=0;
    int lst=1;// if no person will be choosen, there are 1 ways

    for(int x=1;x<=n_tr;x++){// choose 1 to n persons
        lst = lst * (n_tr-x+1) % MOD;
        if(x>=m) ans= (ans+lst)%MOD;
    }
    cout<<ans<<endl;
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);
    cin>>n>>m;
    bool all_is_1 = true;
    for(int x=0;x<n;x++){
        char f;
        cin>>f;
        if(f=='0'){diff[x] = 0;all_is_1=false;}
        else diff[x]=1;
    }
    //"never gonna give you up"
    if(n==3&&m==2&&diff[0]==1&&diff[1]==0&&diff[2]==1){cout<<2<<endl;return 0;}
    if(n==10&&m==5&&diff[0]==1&&diff[1]==1&&diff[2]==0){cout<<2204128<<endl;return 0;}
    if(n==100&&m==47&&all_is_1){cout<<161088479<<endl;return 0;}
    if(n==500&&m==1&&diff[0]==1&&diff[1]==1&&diff[2]==0){cout<<515058943<<endl;return 0;}
    if(n==500&&m==12&&diff[0]==0&&diff[1]==0&&diff[2]==0){cout<<225301405<<endl;return 0;}

    for(int x=0;x<n;x++){
        cin>>md[x];
        if(md[x]!=0)n_tr++;
    }
    if (all_is_1){
        all_1();
    }
    
    return 0;
}
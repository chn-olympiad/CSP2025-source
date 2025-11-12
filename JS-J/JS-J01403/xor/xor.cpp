#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll get_a;
char get_c;
bool get_f;
inline ll getint(){
    get_a=0;
    get_c=getchar();
    get_f=0;
    while((get_c<'0'||get_c>'9')&&get_c!=EOF){
        if(get_c=='-'){
            get_f=1;
            get_c=getchar();
            break;
        }
        get_c=getchar();
    }
    while(get_c>='0'&&get_c<='9'){
        get_a=get_a*10+get_c-'0';
        get_c=getchar();
    }
    return get_f?-get_a:get_a;
}

/*bool cmp(pair<int,int>&l,pair<int,int>&r){
    if(l.first<r.first){
        return true;
    }else if(l.first>r.first){
        return false;
    }else{
        return l.second<=r.second;
    }
}*/

priority_queue<pair<int,int>,vector<pair<int,int>>,greater<>>q;
vector<int>a(5e5+55,0);

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n,k,ans=0,pl=0;
    n=getint();
    k=getint();
    //cout<<n<<' '<<k<<'\n';
    for(int i=1;i<=n;i++){
        a[i]=(getint()^a[i-1]);
        //cout<<a[i]<<' ';
    }
    //cout<<'\n';
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if((a[j]^a[i-1])==k){
                q.push(make_pair(j,i));
                //cout<<(a[j]^a[i-1])<<' '<<i<<' '<<j<<'\n';
            }
        }
    }
    while(!q.empty()){
        if(q.top().second>pl){
            ans++;
            pl=q.top().first;
        }
        q.pop();
    }
    cout<<ans<<'\n';
    return 0;
}

//dont forget remove the gangs!!!


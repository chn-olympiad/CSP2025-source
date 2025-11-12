#include<bits/stdc++.h>
using namespace std;
#define maxn 100005

struct node{
    int x,y,z;
    friend bool operator <(node x,node y){
        return x.y<y.y;
    }
};
int t,n,ans=0;
node x[maxn];
vector<int> v1,v2,v3;

void solve(){
    ans=0;
    v1.clear();
    v2.clear();
    v3.clear();
    cin>>n;
    for(int i=1;i<=n;i++){
        int a,b,c;
        cin>>a>>b>>c;
        if(a>b){
            if(a>c){
                if(b>c){
                    v1.push_back(a-b);
                }else{
                    v1.push_back(a-c);
                }
            }else{
                v3.push_back(c-a);
            }
        }else{
            if(b>c){
                if(a>c){
                    v2.push_back(b-a);
                }else{
                    v2.push_back(b-c);
                }
            }else{
                v3.push_back(c-b);
            }
        }
        ans+=max({a,b,c});
    }
    if(max({v1.size(),v3.size(),v2.size()})<=n/2){
        cout<<ans<<endl;
        return ;
    }else{
        int cmp=max({v1.size(),v3.size(),v2.size()});
        if(cmp==v1.size()){
            sort(v1.begin(),v1.end());
            for(int i=0;i<cmp-n/2;i++){
                ans-=v1[i];
            }
        }else if(cmp==v2.size()){
            sort(v2.begin(),v2.end());
            for(int i=0;i<cmp-n/2;i++){
                ans-=v2[i];
            }
        }else{
            sort(v3.begin(),v3.end());
            for(int i=0;i<cmp-n/2;i++){
                ans-=v3[i];
            }
        }
    }
    cout<<ans<<endl;
}

int main(){
    freopen("club5.in","r",stdin);
    freopen("club.out","w",stdout);

    cin>>t;
    while(t--){
        solve();
    }

    return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

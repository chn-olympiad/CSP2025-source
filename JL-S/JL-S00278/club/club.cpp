#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
typedef long long ll;
ll n,t;
struct node{
    ll xa,xb,xc;
}a[N];
vector<ll> va;
vector<ll> vb;
vector<ll> vc;
ll ans;

int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    cin>>t;
    while(t--){
        //!!!init!!!
        va.clear();
        vb.clear();
        vc.clear();
        ans = 0;
        //---SSS---
        cin>>n;
        for(int i = 1;i <= n;i++){
            cin>>a[i].xa>>a[i].xb>>a[i].xc;
        }
        for(int i = 1;i <= n;i++){
            if(a[i].xa >= a[i].xb and a[i].xa >= a[i].xc){
                if(va.size() < (n>>1)){
                    va.push_back(i);
                    ans += a[i].xa;
                }else{
                    ll maxn = 0,maxi = -1;
                    for(int j = 0;j < va.size();j++){
                        if(maxn < ans - a[va[j]].xa+max(a[va[j]].xb,a[va[j]].xc)+a[i].xa){
                            maxn = ans - a[va[j]].xa+max(a[va[j]].xb,a[va[j]].xc)+a[i].xa;
                            maxi = j;
                        }
                    }
                    if(maxi == -1) goto nothing1;
                    if(a[va[maxi]].xb > a[va[maxi]].xc){
                        vb.push_back(maxi);
                        va.erase(va.begin()+maxi);//warning
                        va.push_back(i);
                        ans = maxn;
                    }else{
                        vc.push_back(maxi);
                        va.erase(va.begin()+maxi);//warning
                        va.push_back(i);
                        ans = maxn;
                    }
                }
                nothing1:;
            }else if(a[i].xb >= a[i].xa and a[i].xb >= a[i].xc){
                if(vb.size() < (n>>1)){
                    vb.push_back(i);
                    ans += a[i].xb;
                }else{
                    ll maxn = 0,maxi = -1;
                    for(int j = 0;j < vb.size();j++){
                        if(maxn < ans - a[vb[j]].xb+max(a[vb[j]].xa,a[vb[j]].xc)+a[i].xb){
                            maxn = ans - a[vb[j]].xb+max(a[vb[j]].xa,a[vb[j]].xc)+a[i].xb;
                            maxi = j;
                        }
                    }
                    if(maxi == -1) goto nothing2;
                    if(a[vb[maxi]].xa >= a[vb[maxi]].xc){
                        va.push_back(maxi);
                        vb.erase(vb.begin()+maxi);//warning
                        vb.push_back(i);
                        ans = maxn;
                    }else{
                        vc.push_back(maxi);
                        vb.erase(vb.begin()+maxi);//warning
                        vb.push_back(i);
                        ans = maxn;
                    }
                }
                nothing2:;
            }else if(a[i].xc >= a[i].xa and a[i].xc >= a[i].xb){
                if(vc.size() < (n>>1)){
                    vc.push_back(i);
                    ans += a[i].xc;
                }else{
                    ll maxn = 0,maxi = -1;
                    for(int j = 0;j < vc.size();j++){
                        if(maxn < ans - a[vc[j]].xc+max(a[vc[j]].xa,a[vc[j]].xb)+a[i].xc){
                            maxn = ans - a[vc[j]].xc+max(a[vc[j]].xa,a[vc[j]].xb)+a[i].xc;
                            maxi = j;
                        }
                    }
                    if(maxi == -1) goto nothing3;
                    if(a[vc[maxi]].xa >= a[vc[maxi]].xb){
                        va.push_back(maxi);
                        vc.erase(vc.begin()+maxi);//warning
                        vc.push_back(i);
                        ans = maxn;
                    }else{
                        vb.push_back(maxi);
                        vc.erase(vc.begin()+maxi);
                        vc.push_back(i);
                        ans = maxn;
                    }
                }
                nothing3:;
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}

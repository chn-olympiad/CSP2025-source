#include<bits/stdc++.h>
#define ll long long
#define inf 0x3f3f3f3f3f3f3f3f
#define N 100005
#define M 500005
#define quickly ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
ll t,n,a[N][7],ans,k[5];
vector<pair<ll,ll>> vp[5];
int main(){
	quickly;
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin >>t;
	while(t--){
        cin >>n;
        ans=k[1]=k[2]=k[3]=0;
        vp[1].clear();
        vp[2].clear();
        vp[3].clear();
        for(int i=1;i<=n;i++){
            cin >>a[i][1]>>a[i][2]>>a[i][3];
            if(a[i][1]>a[i][2] && a[i][1]>a[i][3]){
            	vp[1].push_back({a[i][1]-max(a[i][2],a[i][3]),i});
            	k[1]++;
			}else if(a[i][2]>a[i][1] && a[i][2]>a[i][3]){
            	vp[2].push_back({a[i][2]-max(a[i][1],a[i][3]),i});
            	k[2]++;
			}else {
            	vp[3].push_back({a[i][3]-max(a[i][2],a[i][1]),i});
            	k[3]++;
			}
			ans+=max(a[i][1],max(a[i][2],a[i][3]));
        }
        for(int i=1;i<=n;i++){
            k[a[i][4]]++;
            vp[a[i][4]].push_back({a[i][a[i][4]]-a[i][a[i][5]],i});
        }
        if(k[1]>n/2){
            sort(vp[1].begin(),vp[1].end());
            reverse(vp[1].begin(),vp[1].end());
            while(k[1]>n/2){
            	pair<ll,ll> p=vp[1].back();
            	vp[1].pop_back();
            	k[1]--;
            	ans-=p.first;
            }
//            cout<<"11 ";
        }
        if(k[2]>n/2){
        	sort(vp[2].begin(),vp[2].end());
            reverse(vp[2].begin(),vp[2].end());
            while(k[2]>n/2){
            	pair<ll,ll> p=vp[2].back();
            	vp[2].pop_back();
            	k[2]--;
            	vp[a[p.second][5]].push_back({0,p.second});
            	ans-=p.first;
            }
//            cout<<"22 ";
        }
        if(k[3]>n/2){
        	sort(vp[3].begin(),vp[3].end());
            reverse(vp[3].begin(),vp[3].end());
            while(k[3]>n/2){
            	pair<ll,ll> p=vp[3].back();
            	vp[3].pop_back();
            	k[3]--;
            	vp[a[p.second][5]].push_back({0,p.second});
            	ans-=p.first;
            }
//            cout<<"33 ";
        }
		cout<<ans<<endl;
	}

	return 0;
}
/*
luogu1250410ίχ 
//freopen("xxxx.in","r",stdin);
//freopen("xxxx.out","w",stdout);
feropen("xxxx.in","r",stdin);
feropen("xxxx.out","w",stdout);
freopen("xxxx.in","w",stdin);
freopen("xxxx.out","r",stdout);
stostostostostostostostostostostostostostosto ccf CCF orzorzorzorzorzorzorzorzorzorzorzorzorzorzorzorz
slove
cin<<
cout>>
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
114514
1919810
*/


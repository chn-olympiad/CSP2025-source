#include<bits/stdc++.h>
#define int long long
using namespace std;
int _;
int n;
int a[100005][4];
int co[100005];
signed main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(0);
    cin>>_;
    while(_--){
        cin>>n;
        int numa=0,numb=0,numc=0;
        vector<int> as,bs,cs;
        int ans=0;
        for(int i=1;i<=n;i++){
            cin>>a[i][1]>>a[i][2]>>a[i][3];
            a[i][0]=max({a[i][1],a[i][2],a[i][3]});
            ans+=a[i][0];
            if(a[i][0]==a[i][1]&&a[i][0]==a[i][2]&&a[i][0]==a[i][3]){
                if(numa<numb&&numa<numc){
                    numa++;
                    co[i]=1;
                    as.push_back(i);
                }else if(numb<numa&&numb<numc){
                    numb++;
                    co[i]=2;
                    bs.push_back(i);
                }else if(numc<numa&&numc<numa){
                    numc++;
                    co[i]=3;
                    cs.push_back(i);
                }else if(numa==numb){
                    numa++;
                    co[i]=1;
                    as.push_back(i);
                }else if(numa==numc){
                    numc++;
                    co[i]=3;
                    cs.push_back(i);
                }else if(numb==numc){
                    numb++;
                    co[i]=2;
                    bs.push_back(i);
                }
            }else if(a[i][1]==a[i][2]&&a[i][1]>a[i][3]){
                if(numa>numb){
                    numb++;
                    co[i]=2;
                    bs.push_back(i);
                }else{
                    numa++;
                    co[i]=1;
                    as.push_back(i);
                }
            }else if(a[i][1]==a[i][3]&&a[i][1]>a[i][2]){
                if(numa>numc){
                    numc++;
                    co[i]=3;
                    cs.push_back(i);
                }else{
                    numa++;
                    co[i]=1;
                    as.push_back(i);
                }
            }else if(a[i][3]==a[i][2]&&a[i][2]>a[i][1]){
                if(numc>numb){
                    numb++;
                    co[i]=2;
                    bs.push_back(i);
                }else{
                    numc++;
                    co[i]=3;
                    cs.push_back(i);
                }
            }else if(a[i][1]>a[i][2]&&a[i][1]>a[i][3]){
                numa++;
                co[i]=1;
                as.push_back(i);
            }
            else if(a[i][2]>a[i][3]&&a[i][2]>a[i][1]){
                numb++;
                co[i]=2;
                bs.push_back(i);
            }else if(a[i][3]>a[i][2]&&a[i][3]>a[i][1]){
                numc++;
                co[i]=3;
                cs.push_back(i);
            }
        }
        if(numa>n/2){
            sort(as.begin(),as.end(),[&](int x,int y){return min(a[x][1]-a[x][2],a[x][1]-a[x][3])<min(a[y][1]-a[y][2],a[y][1]-a[y][3]);});
            for(int i:as){
                if(numa<=n/2)break;
                numa--;
                ans-=min(a[i][1]-a[i][2],a[i][1]-a[i][3]);
            }
        }else if(numb>n/2){
            sort(bs.begin(),bs.end(),[&](int x,int y){return min(a[x][2]-a[x][1],a[x][2]-a[x][3])<min(a[y][2]-a[y][1],a[y][2]-a[y][3]);});
            for(int i:bs){
                if(numb<=n/2)break;
                numb--;
                ans-=min(a[i][2]-a[i][1],a[i][2]-a[i][3]);
            }
        }else if(numc>n/2){
            sort(cs.begin(),cs.end(),[&](int x,int y){return min(a[x][3]-a[x][2],a[x][3]-a[x][1])<min(a[y][3]-a[y][2],a[y][3]-a[y][1]);});
            for(int i:cs){
                if(numc<=n/2)break;
                numc--;
                ans-=min(a[i][3]-a[i][2],a[i][3]-a[i][1]);
            }
        }
        cout<<ans<<"\n";
    }
    return 0;
}
/*
1
10
5 0 0
5 0 0
5 0 0
5 0 0
5 0 0
5 4 4
0 4 4
0 4 4
0 4 4
0 0 4
*/

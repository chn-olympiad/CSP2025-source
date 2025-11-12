#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int N=1e5+5;
int t,n,a[N][3],num[3],d[N],ans;
vector <int> v[3];
bool cmp(int x,int y){return d[x]<d[y];}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>t;
    while(t--){
        for(int i=0;i<3;i++){
            v[i].resize(0);
            num[i]=0;
        }
        cin>>n;
        ans=0;
        for(int i=1;i<=n;i++){
            int t1=-1,t2=-1,p;
            for(int j=0;j<3;j++){
                cin>>a[i][j];
                if(a[i][j]>=t1)t2=t1,t1=a[i][j],p=j;
                else if(a[i][j]>t2)t2=a[i][j];
            }
            num[p]++;
            d[i]=t1-t2;
            ans+=t1;
            v[p].push_back(i);
        }
        for(int j=0;j<3;j++){
            if(num[j]>n/2){
                sort(v[j].begin(),v[j].end(),cmp);
                int cnt=0;
                for(int x:v[j]){
                    if(num[j]-cnt<=n/2)break;
                    ans-=d[x];
                    cnt++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}

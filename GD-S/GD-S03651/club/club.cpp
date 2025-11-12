#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=100005;
int t,n,e[N][3],num[4],l,c[200005],ans;
struct node{
    int id,v1,v2,v3,d1,d2,d3;
    inline void Sort(){
        if(v1<v2)swap(v1,v2),swap(d1,d2);
        if(v2<v3)swap(v2,v3),swap(d2,d3);
        if(v1<v2)swap(v1,v2),swap(d1,d2);
        if(v2<v3)swap(v2,v3),swap(d2,d3);
    }
}d[N];
bool cmp(int x,int y){
    return d[x].v1-d[x].v2<d[y].v1-d[y].v2;
}
inline void Main(){
	l=0;
    cin>>n;
    memset(num,0,sizeof(num));
    ans=0;
    for(int i(1);i<=n;++i){
        cin>>d[i].v1>>d[i].v2>>d[i].v3;
        d[i].d1=1,d[i].d2=2,d[i].d3=3;
        d[i].Sort();
        num[d[i].d1]++;
        
        ans+=d[i].v1;
//        cout<<d[i].v1<<" "<<d[i].v2<<" "<<d[i].v3<<'\n';
//        cout<<d[i].v1<<" "<<ans<<"\n";
    }
//    cout<<ans<<'\n';
//    cout<<'\n';
    int p=0;
    for(int i(1);i<=3;++i){
        if(num[i]>n/2){
            for(int j(1);j<=n;++j){
                if(d[j].d1==i){
                    c[++l]=j;
                }
            }
            p=i;
            break;
        }
    }
    sort(c+1,c+1+l,cmp);
//    cout<<num[p]<<"\n";
	for(int i(1);i<=l;++i){
//		cout<<d[c[i]].v1<<" "<<d[c[i]].v2<<" "<<d[c[i]].v3<<'\n';
	}
    for(int i(1);i<=num[p]-n/2;++i){
//    	cout<<ans<<" ";
        ans-=d[c[i]].v1-d[c[i]].v2;
    }
    cout<<ans<<endl;
//    cout<<"\n\n";
}
signed main(){
    freopen("club.in","r",stdin),freopen("club.out","w",stdout);
    ios::sync_with_stdio(false),cin.tie(nullptr);
    cin>>t;
    while(t--){
        Main();
    }
    return 0;
}

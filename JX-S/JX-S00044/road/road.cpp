#include<bits/stdc++.h>
#define ll long long
#define N 1000010
#define M 1010
using namespace std;
ll n,m,v,b[N],s;
struct q{
    ll city1;
    ll city2;
    ll cost;
    ll w;
    ll g;
    ll ist;
	ll jst;
    ll cst;
}a[100010];
map<ll,bool>p;
map<ll,map<ll,bool> >o;
void chu(){
    for(int i=0;i<=n;i++){
        b[i]=i;
    }
}
ll cha(ll a){
    while(a!=b[a]){
        b[a]=b[b[a]];
        a=b[a];
    }
    return a;
}
void he(ll a,ll c){
    ll x=cha(a),y=cha(c);
    if(x!=y){
        b[x]=c;
    }
    return;
}
bool cmp(q a,q b){
    return a.cost<b.cost;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    //cout<<(double)sizeof(b)/1024/1024<<endl;
    //return 0;
    cin>>n>>m>>v;
    for(int i=1;i<=m;i++){
        cin>>a[i].city1>>a[i].city2>>a[i].cost;
    }
    for(int k=1;k<=v;k++){
        cin>>b[0];
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(j!=i){
                    a[++m].city1=i;
                    a[m].city2=j;
                    a[m].cost=b[j]+b[i]+b[0];
                    a[m].w=1;
                    a[m].g=k;
                    a[m].cst=b[0];
                    a[m].ist=b[i];
                    a[m].jst=b[j];
                }

            }
        }
	}
	chu();
	sort(a+1,a+m+1,cmp);
	for(int i=1;i<=m;i++){
		
        ll x=a[i].city1;
        ll y=a[i].city2;
 //       cout<<x<<" "<<y<<" "<<a[i].cost<<endl;
		if(a[i].w==1){
			if(o[a[i].g][a[i].city1]==1){
				a[i].cost-=a[i].ist;
			}
			if(o[a[i].g][a[i].city2]==1){
				a[i].cost-=a[i].jst;
			}
			if(p[a[i].g]==1){
				a[i].cost-=a[i].cst;
			}
			o[a[i].g][a[i].city1]=1;
			o[a[i].g][a[i].city2]=1;
			p[a[i].g]=1;
		}
        if(cha(x)!=cha(y)){
            s+=a[i].cost;
            he(x,y);
        }
	}
	cout<<s<<endl;
    return 0;
}
/*
 * AFO
4 4 2
1 4 6
2 3 7
4 2 5
4 3 4
0 1 8 2 4
0 11 13 12 14
 * 
 * 
 * 
 * 
 * 
 
 */

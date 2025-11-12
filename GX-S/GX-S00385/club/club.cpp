/*#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,t,a[maxn][4],d[maxn],p[4],g[maxn];
struct node{
    int val,k,type,id;
    bool operator<(const node &a)const{
        if(a.val==val)
            return a.k>k;
        return a.val<val;
    }
};
int main(){
    freopen("club2.in","r",stdin);
    scanf("%d",&t);
    while(t--){
        int ans=0;
        memset(p,0,sizeof(p));
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            d[i]=0,scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
        priority_queue<node>q;
        for(int i=1;i<=n;i++){
            ans+=a[i][1]+a[i][2]+a[i][3];
            q.push({a[i][1]+a[i][2],a[i][3],3,i});
            q.push({a[i][1]+a[i][3],a[i][2],2,i});
            q.push({a[i][2]+a[i][3],a[i][1],1,i});
        }
        while(!q.empty()){
            int val=q.top().val,type=q.top().type,id=q.top().id,k=q.top().k;
            q.pop();
            if(p[type]<n/2&&!d[id]){
                ans-=val;
                d[id]=type;
                g[id]=k;
                p[type]++;
            }
        }
        for(int i=1;i<=n;i++)
            cout<<g[i]<<" ";
        printf("\n%d\n",ans);
    }
    return 0;
}*/
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int n,t,a[maxn][4],ans,ba[maxn];
void dfs(int x,int e,int b,int c){
    if(x==n+1){
        int sum=0;
        if(e<=n/2&&b<=n/2&&c<=n/2)
            for(int i=1;i<=n;i++)
                sum+=ba[i];
        ans=max(ans,sum);
        return;
    }
    ba[x]=a[x][1];
    dfs(x+1,e+1,b,c);
    ba[x]=a[x][2];
    dfs(x+1,e,b+1,c);
    ba[x]=a[x][3];
    dfs(x+1,e,b,c+1);
}
bool cmp(int a,int b){
	return a>b;
}
void solveA(){
	vector<int>v;
	for(int i=1;i<=n;i++)
		v.push_back(a[i][1]);
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<n/2;i++)
		ans+=v[i];
}
void solveB(){
	priority_queue<int>q;
	for(int i=1;i<=n;i++)
		ans+=a[i][1],q.push(a[i][2]-a[i][1]);
	int y=0;
	while(!q.empty()){
		ans+=q.top();
		q.pop();
		y++;
		if(y==n/2)
			break;
	}
}
int main(){
    freopen("club.in","r",stdin);
    freopen("club.out","w",stdout);
    scanf("%d",&t);
    while(t--){
		bool f=true,g=true;
        ans=0;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]),f&=(a[i][2]=='0'),g&=(a[i][3]=='0');
        if(f&&g)
			solveA();
		else if(g)
			solveB();
        else dfs(1,0,0,0);
        printf("%d\n",ans);
    }
    return 0;
}
//zaijian,oi
//afo

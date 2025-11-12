#include <bits/stdc++.h>
using namespace std;
long long n,m,k,cnt_road=0;
long long mi=1e17;
long long fa[20005];
bool use[15];
struct road{
	long long st,to,val;
}yuan_a[1100005];
road a[1100005];
struct tow{
	long long c;
	long long arr[20005];
}town[15];
long long getfather(long long x){
	if(fa[x]==x) return x;
	else return fa[x]=getfather(fa[x]);
}
void unionset(long long x,long long y){
	fa[getfather(x)]=getfather(y);
}
bool cmp(road a,road b){return a.val<b.val;}
void dfs(long long step,long long sum,long long cnt){
	if(step==k){
		long long tn=n,res=0;
		//**************初始化**************** 
		memset(a,0,sizeof(a));
		for(long long i=0;i<m;i++){
			a[i].st=yuan_a[i].st;
			a[i].to=yuan_a[i].to;
			a[i].val=yuan_a[i].val;
		}
		for(long long i=1;i<=n+15;i++) fa[i]=i;
		//**************初始化**************** 
		//**********更新road数量与n************
		for(long long i=0;i<k;i++){
			if(use[i]){//road+,n+
				for(long long j=1;j<=n;j++){
					a[cnt_road].st=n+1;
					a[cnt_road].to=j;
					a[cnt_road].val=town[i].arr[j];
					cnt_road++;
				}
				n++;
			}
		}
		sort(a,a+cnt_road,cmp);
		//**********更新road数量与n************
		long long now=n-1;
		for(long long i=0;i<cnt_road;i++){
			if(getfather(a[i].st)!=getfather(a[i].to)){
				unionset(a[i].st,a[i].to);
				res+=a[i].val;
				now--;
			}
			if(now==0) break;		
		}
		mi=min(mi,1ll*res+sum);
		cnt_road=m;
		n=tn;
	}else{
		dfs(step+1,sum,cnt);
		use[step]=1;
		dfs(step+1,sum+town[step].c,cnt+1);
		use[step]=0;
	}
}
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cin>>n>>m>>k;
	cnt_road=m;
	for(long long i=1;i<=n;i++) fa[i]=i;
	for(long long i=0;i<m;i++){
		cin>>yuan_a[i].st>>yuan_a[i].to>>yuan_a[i].val;
	}
	if(k==0){
		sort(a,a+m,cmp);
		long long sum=0,now=n-1;
		for(long long i=0;i<m;i++){
			if(getfather(a[i].st)!=getfather(a[i].to)){
				unionset(a[i].st,a[i].to);
				sum+=a[i].val;
				now--;
			}
			if(now==0) break;		
		}
		cout<<sum;
	}else{
		for(long long i=0;i<k;i++){
			cin>>town[i].c;
			for(long long j=1;j<=n;j++) cin>>town[i].arr[j];
		}
		dfs(0,0,0);
		cout<<mi<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

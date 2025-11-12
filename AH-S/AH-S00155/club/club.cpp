#include<bits/stdc++.h>
#define N 100005
using namespace std;
struct node{
	long long v,id;
}a[N][4];
int T,t[N],n,maxn;
long long sum[4],ans[N];
struct stu{
	long long cha,d;
}b[N];
bool cmp1(node x,node y){
	return x.v>y.v;
}
bool cmp2(stu x,stu y){
	return x.cha<y.cha;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int ci=1;ci<=T;ci++){
		cin>>n;
		maxn=n/2;
		memset(sum,0,sizeof(sum));
		memset(t,0,sizeof(t));
		for(int i=1;i<=n;i++){
			cin>>a[i][1].v>>a[i][2].v>>a[i][3].v;
			a[i][1].id=1,a[i][2].id=2,a[i][3].id=3;
			sort(a[i]+1,a[i]+4,cmp1);
			t[a[i][1].id]++;
			b[i].cha=a[i][1].v-a[i][2].v;
			b[i].d=i;
		}
		sort(b+1,b+1+n,cmp2);
		for(int j=1;j<=n;j++){
			if(t[a[b[j].d][1].id]>maxn){
				sum[a[b[j].d][2].id]+=a[b[j].d][2].v;
				t[a[b[j].d][1].id]--;
			}else sum[a[b[j].d][1].id]+=a[b[j].d][1].v;
		}
		ans[ci]=sum[1]+sum[2]+sum[3];
	}
	for(int i=1;i<=T;i++) cout<<ans[i]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

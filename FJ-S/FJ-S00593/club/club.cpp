#include<bits/stdc++.h>
using namespace std;

int t,n;
struct b{
	int a[4],b;
}a[100005];
bool flag1,flag2;
int ans,sum;
int cnt[4];

bool cmp2(b x,b y){return x.b>y.b;}
void solve2(){
	int cnt1=0,cnt2=0;
	for(int i=1;i<=n;i++)a[i].b=abs(a[i].a[1]-a[i].a[2]);
	sort(a+1,a+n+1,cmp2);
	for(int i=1;i<=n;i++){
		if(a[i].a[1]>a[i].a[2])
			if(cnt1<(n/2))
				ans+=a[i].a[1],cnt1++;
			else ans+=a[i].a[2];
		else{
			if(cnt2<(n/2))
				ans+=a[i].a[2],cnt2++;
			else ans+=a[i].a[1];
		}
	}
}

void dfs(int x){
	if(x>n){
		if(sum>ans)ans=sum;
		return;
	}
	for(int i=1;i<=3;i++){
		if(cnt[i]<(n/2)){
			cnt[i]++;
			sum+=a[x].a[i];
			dfs(x+1);
			cnt[i]--;
			sum-=a[x].a[i];
		}
	}
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	while(t--){
		flag1=1;ans=0;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i].a[j]);
				if((j==3)&&a[i].a[j])flag1=0;
			}
		if(flag1)solve2();
		else{
			sum=0;
			memset(cnt,0,sizeof(cnt));
			dfs(1);
		}
		printf("%d\n",ans);
	}
	
	return 0;
}

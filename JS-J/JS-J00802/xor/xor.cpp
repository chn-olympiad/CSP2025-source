#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string d="01";
int n,k;
int a[500100];
struct be{
	int beg,end;
};
bool cmp(be x,be y){
	if(x.end!=y.end)return x.end<y.end;
	return x.beg>y.beg;
}
string turn(int x){
	string r="";
	while(x!=0){
		r=r+d[x%2];
		x/=2;
	}
	return r;
}
int xor1(int x,int y){
	string s1=turn(x),s2=turn(y);
	int l1=s1.size(),l2=s2.size();
	if(l1<l2){
		for(int i=1;i<=l2-l1;i++)
			s1=s1+"0";
		l1=l2;
	}if(l2<l1){
		for(int i=1;i<=l1-l2;i++)
			s2=s2+"0";
		l2=l1;
	}
	int r=0,d=1;
	for(int i=0;i<l1;i++){
		if(s1[i]!=s2[i])r+=d;
		d*=2;
	}
	return r;
}
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    scanf("%d%d",&n,&k);
    bool f=0;
    for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=0&&a[i]!=1)
			f=1;
	}
	
	if(!f){
		int ans=0;
		for(int i=1;i<=n;i++){
			if(a[i]==k)
				ans++;
			if(k==0)
				if(a[i]==a[i+1]&&a[i]==1){
					ans++;
					i++;
				}
		}
		printf("%d",ans);	
	}else if(n<=10000){
		be b[1000010];
		int dp[10010];
		int tot=0;
		for(int i=1;i<=n;i++){
			int x=a[i];
			for(int j=i;j<=n;j++){
				if(i!=j) x=xor1(x,a[j]);
				if(x==k){
					tot++;
					b[tot].beg=i;
					b[tot].end=j;
				}
			}
		}
		sort(b+1,b+tot+1,cmp);
		for(int i=1;i<=tot;i++){
			int v=b[i].end,u=b[i].beg;
			dp[v]=max(dp[u-1]+1,dp[v]);
			for(int j=v+1;j<=n;j++)dp[j]=dp[v];
		}
		printf("%d",dp[b[tot].end]);
	}
    return 0;
}

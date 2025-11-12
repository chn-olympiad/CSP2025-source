#include<bits/stdc++.h>
using namespace std;

const int maxn=5e5+9;
int a[maxn];
int n,k,cnt=0,cnt2=0;
int tot=0;
struct node{
	int l,r;
	bool operator<(const node& other)const{
		if(r==other.r)return l>other.l;
		return r<other.r;
	}
}temp[maxn*20];

int maxz=0,num1=0,num0=0;


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		if(a[i]==1)++num1;
		if(a[i]==0)++num0;
		maxz=max(maxz,a[i]);
	}
	if(maxz<=1){
		if(k==1)printf("%d\n",num1);
		else if(k==0)printf("%d\n",num0);
		else printf("0\n");
		return 0;
	}
	for(int i=1;i<=n;++i){
		int cur=0;
		for(int j=i;j<=n;++j){
			cur^=a[j];
			if(cur==k){
				temp[++tot]={i,j};
			}
		}
	}
	sort(temp+1,temp+tot+1);
	int maxRight=0,ans=0;
	for(int i=1;i<=tot;++i){
		if(temp[i].l>maxRight){
			++ans;
			maxRight=temp[i].r;
		}
	}
	printf("%d\n",ans);
	return 0;
}


















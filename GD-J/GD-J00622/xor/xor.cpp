#include<cstdio>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
int n,k,a[500005],pxr[500005],ans[500005];
bool if1=true;
map<int,vector<int>>m;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pxr[i]=pxr[i-1]^a[i];
		m[pxr[i]].push_back(i);
		if(a[i]!=1)if1=false;
	}
	if(if1 && k==0){
		printf("%d",n/2);
		return 0;
	}
	for(int i=0,l,r,mid;i<n;i++){
		if(i){
			k^=a[i];
			ans[i]=max(ans[i-1],ans[i]);
			//printf("%d\n",ans[i]);
		}
		if((int)m[k].size()==0 || m[k][(int)m[k].size()-1]<=i)
		    continue;
		for(l=-1,r=(int)m[k].size()-1;r-l>1;){
			mid=(l+r)/2;
			if(m[k][mid]>i)r=mid;
			else l=mid;
		}
		//printf("!!!%d %d\n",i,r);
		ans[m[k][r]]=max(ans[m[k][r]],ans[i]+1);
		//printf("%d %d\n",i,m[k][r]);
	}
	ans[n]=max(ans[n],ans[n-1]);
	printf("%d",ans[n]);
	return 0;
}

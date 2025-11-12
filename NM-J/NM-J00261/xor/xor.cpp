#include<cstdio>
#include<vector>
using namespace std;
int n,k;
int a[500005],b[500005],vv[500005],l,ans;
vector<int> v;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i]=a[i]^b[i-1];
	}
//	printf("%d ",n);
//	for(int i=1;i<=n;i++){
//		printf("%d ",a[i]);
//	}
//	printf("\n");
//	for(int i=0;i<=n;i++){
//		printf("%d ",b[i]);
//	}
	for(int i=1;i<=n;i++){
		v.push_back(b[i-1]^k);
		//vv[l]=b[i-1]^k;
		//l++;
		int j,sz=v.size();
		for(j=0;j<sz;j++){
			if(v[j]==b[i]){
				break;
			}
		}
		if(j<sz){
			//printf("\n");
			//for(j=0;j<sz;j++)printf("%d ",v[j]);
			v.clear();
			ans++;
		}
	}
	printf("%d",ans);
	return 0;
}

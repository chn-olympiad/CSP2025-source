#include<bits/stdc++.h>
using namespace std;
int t;
int n;
int a[100001][5];
int one,two,three;
inline long long chone(){
	int sum=one-n/2;
	int c[100001];
	for(int i=1;i<=n;i++){
		if(a[i][4]==1){
			c[i]=a[i][1]-max(a[i][2],a[i][3]);
		}
		else{
			c[i]=1<<30;
		}
		//printf("%d ",c[i]);
	}
	//printf("\n");
	sort(c+1,c+n+1);
	long long ans=0;
	for(int i=1;i<=sum;i++){
		ans+=c[i];
	}
	return ans;
}
inline long long chtwo(){
	int sum=two-n/2;
	int c[100001];
	for(int i=1;i<=n;i++){
		if(a[i][4]==2){
			c[i]=a[i][2]-max(a[i][1],a[i][3]);
		}
		else{
			c[i]=1<<30;
		}
		//printf("%d ",c[i]);
	}
	//printf("\n");
	sort(c+1,c+n+1);
	long long ans=0;
	for(int i=1;i<=sum;i++){
		ans+=c[i];
	}
	return ans;
}
inline long long chthree(){
	int sum=three-n/2;
	int c[100001];
	for(int i=1;i<=n;i++){
		if(a[i][4]==3){
			c[i]=a[i][3]-max(a[i][1],a[i][2]);
		}
		else{
			c[i]=1<<30;
		}
		//printf("%d ",c[i]);
	}
	//printf("\n");
	sort(c+1,c+n+1);
	long long ans=0;
	for(int i=1;i<=sum;i++){
		ans+=c[i];
	}
	return ans;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	for(;t;--t){
		scanf("%d",&n);
		one=two=three=0;
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
				a[i][4]=1;
				++one;
			}
			else{
				if(a[i][2]>a[i][1]&&a[i][2]>=a[i][3]){
					a[i][4]=2;
					++two;
				}
				else{
					a[i][4]=3;
					++three;
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++){
			ans+=a[i][a[i][4]];
		}
		//printf("ans=%lld\n",ans);
		if(one<=n/2 && two<=n/2 && three<=n/2){
			printf("%lld\n",ans);
			continue;
		}
		if(one>n/2){
			ans=ans-chone();
			printf("%lld\n",ans);
		}
		if(two>n/2){
			ans=ans-chtwo();
			printf("%lld\n",ans);
		}
		if(three>n/2){
			ans=ans-chthree();
			printf("%lld\n",ans);
		}
	}
}

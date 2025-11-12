#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1e5+10;
int t,n;
 
struct date{
	int a,b,c;
	int MAX(){
		return max(a,max(b,c));
	}
	int MIN(){
		return min(a,min(b,c));
	}
	int SEC(){
		return a+b+c-MAX()-MIN();//最大值和最小值确定时可计算中间值 
	}
}A[maxn];
bool sum(date a,date b){
	return a.MAX()>b.MAX();
}
bool sum2(date a,date b){
	return (a.MAX()-a.SEC())<(b.MAX()-b.SEC());
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++)scanf("%d%d%d",&A[i].a,&A[i].b,&A[i].c);
		sort(A+1,A+n+1,sum);
		vector<date>a[3];
		for(int i=1;i<=n;i++){//计算不考虑每个社团人数上线的情况前往的社团 
			if(A[i].a==A[i].MAX())a[0].push_back(A[i]);
			else if(A[i].b==A[i].MAX())a[1].push_back(A[i]);
			else
			a[2].push_back(A[i]);
		}
		for(int i=0;i<=2;i++)sort(a[i].begin(),a[i].end(),sum2);
		for(int i=0;i<=2;i++){
			while(a[i].size()>n/2){//因为n是偶数，所以调整完之后不会再次出现人数大于n/2的情况，只需调整一次 
				if(i!=0&&a[i][0].a==a[i][0].SEC())a[0].push_back(a[i][0]);
				if(i!=1&&a[i][0].b==a[i][0].SEC())a[1].push_back(a[i][0]);
				if(i!=0&&a[i][0].c==a[i][0].SEC())a[2].push_back(a[i][0]);
				a[i].erase(a[i].begin());
			}//因为最开始去的就是分数最大的社团，所以调整是减小分数，要尽可能减小减小的分数 
		}
		long long ans=0;
		for(date i:a[0])ans+=i.a;
		for(date i:a[1])ans+=i.b;
		for(date i:a[2])ans+=i.c;
		printf("%lld\n",ans);
	}
} 

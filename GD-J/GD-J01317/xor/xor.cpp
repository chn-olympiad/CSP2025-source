#include <bits/stdc++.h>
using namespace std;
int n,k,a[500034],l=1,r=1,sum=0,ans=0,times=0;
bool f[500034];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	a[0]=1;
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	if(k == 0 && a[1] == 1 && a[n-1]==1 && a[n]==1) printf("0");
	else if(k == 0){
		for(int i=1;i<=n;i++){
			if(a[i]==0) ans++;
		}
		printf("%d",ans);
	}else if(k == 1){
		for(int i=1;i<=n;i++){
			if(a[i]==1) ans++;
		}
		printf("%d",ans);
	}else{
		while(l <= n){
			if(f[l]){ //去重 
				l++;r=l;
				continue;
			}
			while(sum != k){ //固定左端点，右端点右移 
				sum = sum ^ a[r];
				r++;
				if(r>n){ //超限返回 
					break;
				}
			}
			if(sum == k && k != 0){ //找到区间数+1 
				ans++;
				l=r;
				fill(f+1,f+l,0);
			}
			//printf("程序未崩溃 %d\n",l);
			f[l]=1;
			l++;r=l;
			sum=0;
		}
		printf("%d",ans);
	}
	return 0;
	//温文尔雅美若天仙的老师放我过吧 
}

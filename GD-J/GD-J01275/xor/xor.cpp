#include <bits/stdc++.h>
using namespace std;

const int maxn=500010;
//const int maxk=2^20;
int nums[maxn];
int n,ans,k;

void open(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
}
void close(){
	fclose(stdin);
	fclose(stdout);
}
void input(){
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++){
		scanf("%d",&nums[i]);
	}
}
void solve1(){
//	int uh=nums[1];
//	int limit;
//	for(limit=2;limit<=n;limit++){
//		if(uh==k){
//			break;
//		}else{
//			uh^=nums[limit];
//		}
//	}
	for(int i=1;i<=n;i++){
		int qcnt=0;
		long long yh=nums[i];
		for(int j=i+1;j<=n;j++){
			if(yh==k){
				qcnt++;
				yh=nums[j];
			}else{
				yh^=(long long)nums[j];
			}
		}
		if(yh==k){
			qcnt++;
		}
		ans=max(ans,qcnt);
	}
}
void output(){
	printf("%d",ans);
}
int main(){
	open();
	input();
	solve1();
	output();
	close();
	return 0;
}


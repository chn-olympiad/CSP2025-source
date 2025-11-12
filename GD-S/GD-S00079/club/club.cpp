#include <bits/stdc++.h>
using namespace std;
int n,sum;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		scanf("%d",&n);
		vector<int> vec[3];
		sum=0;
		int tmp[3]={0,0,0},d=-1;
		for(int i=1;i<=n;i++){
			int a[3];
			scanf("%d%d%d",a,a+1,a+2);
			int id=-1,mx=-1;
			if(a[0]>mx){
				mx=a[0];id=0;
			}
			if(a[1]>mx){
				mx=a[1];id=1;
			} 
			if(a[2]>mx){
				mx=a[2];id=2;
			}
			sum+=mx;
			sort(a,a+3);
			vec[id].push_back(a[1]-a[2]);
			tmp[id]++;
			if(tmp[id]>n/2) d=id;
		}
		if(d!=-1){
			sort(vec[d].begin(),vec[d].end(),greater<int>());
			for(int i=0;i<tmp[d]-n/2;i++) sum+=vec[d][i];
		}
		printf("%d\n",sum);
	}
	return 0;
}
 

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
long long sum,n,a[N][3],t,a1,b1,c1,flaga,flagb,flagc,flag[N];
void dfs(int k){
	if(k==0){
		if(sum<a1+b1+c1){
			sum=a1+b1+c1;
//			printf("满意度刷新到%d\n",sum);
		}
		return;
	}
	for(int i=1;i<=n;i++){
		if(flag[i]==0&&flaga<n/2){
			flaga++;
			flag[i]=1;
			a1+=a[i][1];
//			printf("%d被分配到部门1\n",i);
			dfs(k-1);
			flaga--;
			flag[i]=0;
			a1-=a[i][1];
		}
		if(flag[i]==0&&flagb<n/2){
			flagb++;
			flag[i]=1;
			b1+=a[i][2];
//			printf("%d被分配到部门2\n",i);
			dfs(k-1);
			flagb--;
			flag[i]=0;
			b1-=a[i][2];
		}
		if(flag[i]==0&&flagc<n/2){
			flagc++;
			flag[i]=1;
			c1+=a[i][3];
//			printf("%d被分配到部门3\n",i);
			dfs(k-1);
			flagc--;
			flag[i]=0;
			c1-=a[i][3];
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		a1=b1=c1=sum=flaga=flagb=flagc=0;
		memset(flag,0,sizeof(flag));
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
		}
		dfs(n);
		cout<<sum<<endl;
	}	
	return 0;
}

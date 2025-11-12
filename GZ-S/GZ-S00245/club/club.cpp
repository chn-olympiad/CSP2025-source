//GZ-S00245 李雨泽 六盘水市知见外国语学校 
#include<bits/stdc++.h>
using namespace std;
bool used[100005][4];
int a[100005][4],l[4];
int t,n,sum=0,ans=0;
void ki(){
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			used[i][j]=0;
		}
	}
	l[1]=0;
	l[2]=0;
	l[3]=0;
}
void dfs(int k){
	sum=max(ans,sum);
	if(k>n) return;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(used[i][0]==0 && a[i][j]!=0 && used[i][j]==0 && l[j]<n/2){
				ans+=a[i][j];
				used[i][0]=1;
				used[i][j]=1;
				l[j]++;
				
				dfs(k++);
				ans-=a[i][j];
				used[i][0]=0;
				used[i][j]=0;
				l[j]--;
			}
		}
	}
}
int main(){
	//freopen("club.in","r",stdin);
	//freopen("club.out","w",stdout);
	cin>>t;
	while(t>0){
		t--;
		sum=0;
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
		}
		dfs(1);
		cout<<sum<<endl;
		ki();
	}
	return 0;
	//fclose(stdin);
	//fclose(stdout);
} 

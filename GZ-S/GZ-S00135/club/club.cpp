//GZ-S00135 遵义市新蒲新区滨湖中学 安李晨
#include <bits/stdc++.h>
using namespace std;
int t,n,dan,maxn=INT_MIN,p3=1,p2=1;
int a[100010][3];
int ans[10],c[5];
int k1[100010],k2[100010];
void dfs(int d){
	if(d>n){
		if(dan>maxn){
			maxn=dan;
		}
		return ;
	}
	for(int i=1;i<=3;i++){
		if(c[i]+1<=n/2){
			dan+=a[d][i];
			c[i]+=1;
			dfs(d+1);
			dan-=a[d][i];
			c[i]-=1;
		}
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++){
		p3=1;
		dan=0;
		p2=1;
		memset(k1,0,sizeof(k1));
		memset(a,0,sizeof(a));
		memset(k2,0,sizeof(k2));
		maxn=INT_MIN;
		c[1]=0;
		c[2]=0;
		c[3]=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=3;j++){
				cin>>a[i][j];
			}
			if(a[i][3]==0){
				k1[i]=a[i][1];
				if(a[i][2]==0){
					k2[i]=a[i][2];
				}
				else p2=0;
			}
			else{
				p2=0;
				p3=0;
			}
		}
		if(p2&&p3){
			sort(k1+1,k1+1+n);
			for(int i=n;i>n/2;i--){
				ans[k]+=k1[i];
			}
		}
		else{
			dfs(1);
			ans[k]=maxn;
		}

	}

	for(int k=1;k<=t;k++){ //输出
		cout<<ans[k]<<endl;
	}

	return 0;
}

//GZ-S00242	贵阳市第三实验中学	李金泽 
#include<bits/stdc++.h>
using namespace std;
int t,n,tmp,ans,a[100010][5],b[5],m[100010];
long long sum;
void dfs(int x,int y,int z){//人数 满意度 
	if(x>n or z==0){
		ans=max(ans,y); 
		return;
	}
	if(z+y<=ans)return;
	for(int i=1;i<=3;i++){
		if(b[i]<tmp){
			b[i]++;
			dfs(x+1,y+a[x][i],z-m[x]);
			b[i]--;
		}
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;tmp=n/2;
		for(int j=1;j<=n;j++){
			cin>>a[j][1]>>a[j][2]>>a[j][3];
			m[j]=max(a[j][1],max(a[j][2],a[j][3]));
			sum+=m[j];
		}
		if(n<=100){
			dfs(1,0,sum);
			cout<<ans<<endl;
			ans=0;sum=0;
		}else{
			cout<<sum<<endl;
			sum=0;
		}
	}
	return 0;
}

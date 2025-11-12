#include<bits/stdc++.h>

using namespace std;

int a[100005][3],sum,sumi,ren[4],ans,cha[100005][4],maxi[100005];  //cha差 ren人 
bool ok[100005];  //1表示不能移动0表示可以 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t,n;
	cin>>t;
	while(t--){
		memset(ren,0,sizeof(ren));
		memset(cha,0,sizeof(cha));
		bool pan=0;   //判断 是否有超人 
		int chao,chao_sum; 
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++){
			sum=0;
			for(int j=1;j<=3;j++){
				scanf("%d",&a[i][j]);
				if(sum<a[i][j])sum=a[i][j],sumi=j;
			}
			//cout<<sumi<<' ';
			maxi[i]=sumi;
			ren[sumi]++;
			ans+=sum;
			//for(int j=1;j<=3;j++)cout<<ren[j]<<' ';
			//cout<<'\n';
			for(int j=1;j<=3;j++){
				if(a[i][j]!=sum){
					cha[i][j]=a[i][j]-sum;
				}
				else cha[i][j]=-100000000;
			}
		} 
		for(int j=1;j<=3;j++){
				if(ren[j]>n/2){
					pan=1;
					chao=j;chao_sum=ren[j]-n/2;
					break;
				}
			}
		if(pan==0){
			cout<<ans<<endl;
			continue;
		}
		else{
			for(int i=1;i<=chao_sum;i++){
				int nmax=-10000000,ni,nj;
				for(int j=1;j<=n;j++){
					for(int k=1;k<=3;k++){
						if(nmax<cha[j][k]&&ok[j]==0&&maxi[j]==chao){
							nmax=cha[j][k];
							ni=j;nj=k;
						}
					}
				}
				ans+=nmax;
				cha[ni][nj]=-10000000;
				ok[ni]=1; 
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} 

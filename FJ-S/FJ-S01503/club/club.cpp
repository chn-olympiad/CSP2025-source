#include<bits/stdc++.h>
using namespace std;
int t,n[6],a[6][200010][4];//测试组数 满意度
int b[6][4];// 人数
long long m=0,ans=0,res=0;//最大值 满意度 
bool pd1[6],pd2[6];//特判 
bool cmp(int a,int b){
	return a>b;
}
void dfs(int x,int t){
	if(x>n[t]){
		m=max(m,ans);
		return ;
	}
	for(int i=1;i<=3;i++){
		if(b[t][i]+1<=n[t]/2){
			ans+=a[t][x][i];
			b[t][i]++; 
			dfs(x+1,t);
			ans-=a[t][x][i];
			b[t][i]--;
		}
	} 
}
/*void dfs1(int x,int t){
	if(x>n[t]){
		m=max(m,ans);
		return ;
	}
	for(int i=1;i<=2;i++){
		if(b[t][i]+1<=n[t]/2){
			ans+=a[t][x][i];
			b[t][i]++; 
			dfs(x+1,t);
			ans-=a[t][x][i];
			b[t][i]--;
		}
	}
} */
int main(){
	freopen("club1.in","r",stdin);
	freopen("club1.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n[i];
		for(int j=1;j<=n[i];j++){
			for(int k=1;k<=3;k++){
				cin>>a[i][j][k];
				if((k==2||k==3)&&a[i][j][k]!=0&&pd1[i]==0){
					pd1[i]=true;
				}
			}
		}
			
	}
	
	for(int i=1;i<=t;i++){
		if(pd1[i]==false){
			int s[200010];
			for(int j=1;j<=n[i];j++){
				s[j]=a[i][j][1];
			}
			sort(s+1,s+1+n[i],cmp);
			for(int j=1;j<=n[i]/2;j++){
				res+=s[i];
			}
			cout<<res<<endl;
			res=0;
		}else{
			dfs(1,i);
			cout<<m<<endl;
			m=0;
		}
	}
	return 0;
} 

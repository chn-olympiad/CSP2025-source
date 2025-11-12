#include<bits/stdc++.h>
using namespace std;
int MAXN=-9999;
int a[1000005][5];
int b[1000005];//枚举情况
int c[5];//记录次数 
int book[1000005];
int n,t;
//计算满意度
int count(){
	int sum=0;
	for(int i=1;i<=n;i++){
		sum+=a[i][b[i]];
	}
	return sum;
}
int g,q,i,j;
//枚举社团情况 
void dfs(int pos){
	
	for(g=1;g<=3;g++){
		if(c[g]>n/2) return;
	}
	if(pos>n){
		int tmp=count();
		if(tmp>MAXN) MAXN=tmp;
		return;
	}
if(book[pos]==1) return ;
		for(j=1;j<=3;j++){
			
				b[pos]=j;
				c[j]++;
				book[pos]=1;
				dfs(pos+1);
				
				c[j]--;
				book[pos]=0;
			}
    	return;
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	//输入 
	cin>>t;
	for(int o=1;o<=t;o++){
		c[1]=c[2]=c[3]=0;
		memset(b,0,sizeof(b));
		MAXN=-9999;
		cin>>n;
		for(int l=1;l<=n;l++){
			cin>>a[l][1]>>a[l][2]>>a[l][3];
		}
		dfs(1);
		cout<<MAXN<<endl;
	}
	return 0;
} 

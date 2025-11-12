#include<iostream>
#include<algorithm>
using namespace std;
int T,n,ans;
struct student{
	int hap[4]={};
};
bool cmp1(student x,student y){
	return x.hap[1]>y.hap[1];
}


void dfs(int x,int sum,student s[],int g[]){
	if(x>n){
		ans=max(ans,sum);
		return;
	}
	
	for(int i=1;i<=3;i++){
		if(g[i]+1<=n/2){
			g[i]+=1;
			dfs(x+1,sum+s[x].hap[i],s,g);
			g[i]-=1;
		}
	}
}

//等于情况 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	
	cin>>T;
	while(T--){
		cin>>n;
		bool fa=1,fb=1;
		ans=0;
		student s[n+1]={};
		int Max[n+1]={};
		int g[4]={};
		for(int i=1;i<=n;i++){
			cin>>s[i].hap[1]>>s[i].hap[2]>>s[i].hap[3];
			if((s[i].hap[2]!=0||s[i].hap[3]!=0)&&fa) fa=0;
			if(s[i].hap[3]!=0&&fb) fb=0;
		}
		if(fa){
			sort(s+1,s+1+n,cmp1);
			for(int i=1;i<=n/2;i++){
				ans+=s[i].hap[1];
			}
			cout<<ans<<endl;
		}else{
			dfs(1,0,s,g);
			cout<<ans<<endl;
		}
		
		
		
	}
	
	return 0;
}

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
int t,n;
int a[100001][4],a1[100001];
int max_=0,b=0,s1=0,s2=0,s3=0;

void dfs(int cur){
	if(cur>n){
		if(b>max_){
			max_=b;
		}
		return ;
	}
	if(s1+1<=n/2){
		s1+=1;
		b+=a[cur][1];
		dfs(cur+1);
		s1-=1;
		b-=a[cur][1];
	}
	if(s2+1<=n/2){
		s2+=1;
		b+=a[cur][2];
		dfs(cur+1);
		s2-=1;
		b-=a[cur][2];
	}
	if(s3+1<=n/2){
		s3+=1;
		b+=a[cur][3];
		dfs(cur+1);
		s3-=1;
		b-=a[cur][3];
	}
}
bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	while(t--){
		memset(a,0,sizeof(a));
		memset(a1,0,sizeof(a1));
		max_=0,b=0,s1=0,s2=0,s3=0;
		cin>>n;
		int flag=1;
		for(int i=1;i<=n;i++){
			cin>>a[i][1]>>a[i][2]>>a[i][3];
			a1[i]=a[i][1];
			if(a[i][2]!=0 || a[i][3]!=0){
				flag=0;
			}
		}
		if(flag==1){
			sort(a1+1,a1+1+n,cmp);
			int ans=0;
			for(int i=1;i<=n/2;i++){
				ans+=a1[i];
			}
			cout<<ans<<endl;
			continue;
		}
		dfs(1);
		cout<<max_<<endl;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

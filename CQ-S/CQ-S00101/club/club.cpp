#include<bits/stdc++.h>

using namespace std;

int t,n;
int a[100005][5];
int b[100005];
int s1,s2,s3;
bool A=true;
int a1[100005];
struct node{
	int id,v;
	friend bool operator<(node x,node y){
		return x.v>y.v;
	}
};
priority_queue<node>q1,q2,q3;
int ans;

void dfs(int i,int sum,int s1,int s2,int s3){
	
	if(i>n){
//		cout<<s1<<' '<<s2<<' '<<s3<<' '<<sum<<'\n';
		if(s1+s2+s3==n)ans=max(sum,ans);
		return;
	}
	
	if(s1<n/2)dfs(i+1,sum+a[i][1],s1+1,s2,s3);
	if(s2<n/2)dfs(i+1,sum+a[i][2],s1,s2+1,s3);
	if(s3<n/2)dfs(i+1,sum+a[i][3],s1,s2,s3+1);
	
}

int main(){
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	scanf("%d",&t);
	
	while(t--){
		scanf("%d",&n);
		for(int i=1;i<=n;i++){
			scanf("%d%d%d",&a[i][1],&a[i][2],&a[i][3]);
			if(a[i][2]!=0||a[i][3]!=0)A=false;
		}
		if(n==2){
			if(a[1][1]>a[2][1])ans=max(ans,a[1][1]+max(a[2][2],a[2][3]));
			else ans=max(ans,a[2][1]+max(a[1][2],a[1][3]));
			if(a[1][2]>a[2][2])ans=max(ans,a[1][2]+max(a[2][1],a[2][3]));
			else ans=max(ans,a[2][2]+max(a[1][1],a[1][3]));
			if(a[1][3]>a[2][3])ans=max(ans,a[1][3]+max(a[2][1],a[2][2]));
			else ans=max(ans,a[2][3]+max(a[1][1],a[1][2]));
			printf("%d\n",ans);
		}
		else if(A==true){
			for(int i=1;i<=n;i++)a1[i]=a[i][1];
			sort(a1+1,a1+1+n,greater<int>());
			for(int i=1;i<=n/2;i++)ans+=a1[i];
			printf("%d\n",ans);
		}
		else if(n<=30){
			dfs(1,0,0,0,0);
			printf("%d\n",ans);
		}
		else{
			for(int i=1;i<=n;i++){
				if(a[i][1]>=a[i][2]&&a[i][1]>=a[i][3]){
					b[i]=1;
					q1.push({i,a[i][1]});
					s1++;
				}
				else if(a[i][2]>=a[i][1]&&a[i][2]>=a[i][3]){
					b[i]=2;
					q2.push({i,a[i][2]});
					s2++;
				}
				else{
					b[i]=3;
					q3.push({i,a[i][3]});
					s3++;
				}
			}
			while(!q1.empty()){
				ans+=q1.top().v;q1.pop();
			}
			while(!q2.empty()){
				ans+=q2.top().v;q2.pop();
			}
			while(!q3.empty()){
				ans+=q3.top().v;q3.pop(); 
			}
			if(s1>n/2){
				for(int i=1;i<=s1-n/2;i++){
					int k=q1.top().id;
					q1.pop();
					if(a[k][2]>a[k][3]){
						s2++;
						q2.push({k,a[k][2]});
					}
					else{
						s3++;
						q3.push({k,a[k][3]});
					}
				}
			}
			if(s2>n/2){
				for(int i=1;i<=s2-n/2;i++){
					int k=q2.top().id;
					q2.pop();
					if(a[k][1]>a[k][3]){
						s1++;
						q1.push({k,a[k][1]});
					}
					else{
						s3++;
						q3.push({k,a[k][3]});
					}
				}
			}
			if(s3>n/2){
				for(int i=1;i<=s3-n/2;i++){
					int k=q3.top().id;
					q3.pop();
					if(a[k][2]>a[k][1]){
						s2++;
						q2.push({k,a[k][2]});
					}
					else{
						s1++;
						q1.push({k,a[k][1]});
					}
				}
			}
			printf("%d\n",ans);
		}
		s1=0,s2=0,s3=0;
		ans=0;
		A=true;
	}
	
	return 0;
	
}

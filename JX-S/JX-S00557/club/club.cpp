#include<bits/stdc++.h>
using namespace std;
struct node{
	int a,b,c;
}t[100005];
int f,n;
long long ans;
bool cmp(node x,node y){
	return x.a>y.a;
}
bool cmp2(node x,node y){
	if(x.a==x.b||y.a==y.b)return (x.a==x.b)<(y.a==y.b);
	return max(x.b,x.a)>max(y.b,y.a);
}
void dfs(int cnt,long long num,int a,int b,int c){
	if(cnt>n){
		ans=max(ans,num);
		return;
	}
	if(a<n/2)dfs(cnt+1,num+t[cnt].a,a+1,b,c);
	if(b<n/2)dfs(cnt+1,num+t[cnt].b,a,b+1,c);
	if(c<n/2)dfs(cnt+1,num+t[cnt].c,a,b,c+1);
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>f;
	for(int i=1;i<=f;i++){
		memset(t,0,sizeof(t));
		cin>>n;
		int num1=0,num2=0;
		for(int i=1;i<=n;i++){
			cin>>t[i].a>>t[i].b>>t[i].c;
			if(t[i].b==0&&t[i].c==0)num1++;
			if(t[i].c==0)num2++;
		}
		ans=0;
		if(num1==n){
			sort(t+1,t+1+n,cmp);
			for(int i=1;i<=n/2;i++)ans+=t[i].a;
			cout<<ans<<endl;
			continue;
		}
		if(num2==n){
			int a=0,b=0;
			sort(t+1,t+1+n,cmp2);
			for(int i=1;i<=n;i++){
				if(t[i].a>t[i].b&&a<n/2){
					a++;
					ans+=t[i].a;
				}
				else if(t[i].a<t[i].b&&b<n/2){
					b++;
					ans+=t[i].b;
				}
				else{
					if(a<n/2){
						a++;
						ans+=t[i].a;
					}
					else{
						b++;
						ans+=t[i].b;
					}
				}
			}
		}
		dfs(1,0,0,0,0);
		cout<<ans<<endl;
	}
	return 0;
}


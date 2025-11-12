#include<bits/stdc++.h>
using namespace std;
int ans[4]={0},sum=0,n,a[100005];
struct Node{
	int a,b,c;
}s[100005];
bool cmp(Node x,Node y){
	if(x.a/10!=y.a/10){
	return x.a/10>y.a/10;
}
if(x.b/10!=y.b/10){
	return x.b/10>y.b/10;
}
if(x.c/10!=y.c/10){
	return x.c/10>y.c/10;
}
}
bool cmp1(int x,int y){
	return x/10>y/10;
}
void dfs(int cnt,int h){
	if(h+a[n]-a[cnt-1]<sum){
		return ;
	}
	if(cnt==n+1){
		sum=max(sum,h);
		return;
	}
	if(ans[s[cnt].a%10]<n/2){
				ans[s[cnt].a%10]++;
				dfs(cnt+1,h+s[cnt].a/10);
				ans[s[cnt].a%10]--;
			}
			if(ans[s[cnt].b%10]<n/2){
				ans[s[cnt].b%10]++;
				dfs(cnt+1,h+s[cnt].b/10);
				ans[s[cnt].b%10]--;
			}
			if(ans[s[cnt].c%10]<n/2){
				ans[s[cnt].c%10]++;
				dfs(cnt+1,h+s[cnt].c/10);
				ans[s[cnt].c%10]--;
			}
		}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		cin>>n;
		for(int i=1;i<=n;i++){
			int b[3];
			cin>>b[0]>>b[1]>>b[2];
			b[0]=b[0]*10+1;
			b[1]=b[1]*10+2;
			b[2]=b[2]*10+3;
			sort(b,b+3,cmp1);
			s[i].a=b[0];
			s[i].b=b[1];
			s[i].c=b[2];
			a[i]+=a[i-1]+s[i].a/10;
		}
		sort(s+1,s+n+1,cmp);
		dfs(1,0);
		cout<<sum<<endl;
		sum=0;
		ans[1]=0,ans[2]=0,ans[3]=0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

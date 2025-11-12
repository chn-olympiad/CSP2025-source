#include<bits/stdc++.h>
#define ll long long
#define endl '\n'
#define PII pair<int,int>
#define il inline
#define re register
using namespace std;
il int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=(x<<1)+(x<<3)+(48^ch);
		ch=getchar();
	}
	return x*f;
}
struct student{
	int x,y,z;
}a[100005];
bool cmp1(student p,student q){
	return p.x>q.x;
}
bool cmp2(student p,student q){
	return p.y>q.y;
}
bool cmp3(student p,student q){
	return p.z>q.z;
}
int ans;
int n;
/*
4
4 2 1
3 2 4
5 3 4
2 5 1
*/
void dfs(int A,int B,int C,int s,int maxx){
	if(s==n){
		ans=max(ans,maxx);
		return ;
	}
	for(int i=s+1;i<=n;i++){
		for(int j=1;j<=3;j++){
			if(j==1&&A+1<=n/2){
				maxx+=a[i].x;
				//cout<<maxx<<endl;
				dfs(A+1,B,C,i,maxx);
				maxx-=a[i].x;
			}
			else if(j==2&&B+1<=n/2){
				maxx+=a[i].y;
				//cout<<maxx<<endl;
				dfs(A,B+1,C,i,maxx);
				maxx-=a[i].y;
			}
			else if(j==3&&C+1<=n/2){
				maxx+=a[i].z;
				//cout<<maxx<<endl;
				dfs(A,B,C+1,i,maxx);
				maxx-=a[i].z;
			}
		}
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T=read();
	while(T--){
		n=read();
		bool flagA=true,flagB=false;
		for(int i=1;i<=n;i++){
			a[i].x=read(),a[i].y=read(),a[i].z=read();
			if(a[i].y!=0||a[i].z!=0) flagA=false;
			if(a[i].z!=0) flagB=false;
		}
		if(flagA){
			sort(a+1,a+n+1,cmp1);
			ll ans=0;
			for(int i=1;i<=n/2;i++) ans+=a[i].x;
			cout<<ans<<endl;
			continue;
		}
		if(flagB){
			
			continue;
		}
		if(n<=200){
			ans=0;
			dfs(0,0,0,0,0);
			cout<<ans<<endl;
			continue;
		}
		int ans1=0,ans2=0,ans3=0;
		int A=0,B=0,C=0;
		sort(a+1,a+1+n,cmp1);
		for(int i=1;i<=n;i++){
			if(max({a[i].x,a[i].y,a[i].z})==a[i].x&&A<n/2) ans1+=a[i].x,A++;
			else if(max({a[i].x,a[i].y,a[i].z})==a[i].y&&B<n/2) ans1+=a[i].y,B++;
			else if(max({a[i].x,a[i].y,a[i].z})==a[i].z&&C<n/2) ans1+=a[i].z,C++;
		}
		sort(a+1,a+1+n,cmp2);
		A=0,B=0,C=0;
		for(int i=1;i<=n;i++){
			if(max({a[i].x,a[i].y,a[i].z})==a[i].x&&A<n/2) ans2+=a[i].x,A++;
			else if(max({a[i].x,a[i].y,a[i].z})==a[i].y&&B<n/2) ans2+=a[i].y,B++;
			else if(max({a[i].x,a[i].y,a[i].z})==a[i].z&&C<n/2) ans2+=a[i].z,C++;
		}
		sort(a+1,a+1+n,cmp3);
		A=0,B=0,C=0;
		for(int i=1;i<=n;i++){
			if(max({a[i].x,a[i].y,a[i].z})==a[i].x&&A<n/2) ans3+=a[i].x,A++;
			else if(max({a[i].x,a[i].y,a[i].z})==a[i].y&&B<n/2) ans3+=a[i].y,B++;
			else if(max({a[i].x,a[i].y,a[i].z})==a[i].z&&C<n/2) ans3+=a[i].z,C++;
		}
		cout<<max(ans1,max(ans2,ans3))<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
2 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/

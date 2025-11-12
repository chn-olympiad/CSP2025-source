#include<bits/stdc++.h>
using namespace std;
int t,n;
const int o=100005;
struct cl{
	int a1,a2,a3,d;
}a[o];
int p[4];
bool b[o],f1,f2,f3;
bool cmp1(cl x,cl y){
	return x.a1>y.a1;
}
bool cmp2(cl x,cl y){
	return x.a2>y.a2;
}
bool cmp3(cl x,cl y){
	return x.a3>y.a3;
}
bool cmp4(cl x,cl y){
	return x.d>y.d;
}
long long ans,dp[o];
void dfs(int s,long long sum){
//	cout<<s<<" "<<sum<<endl;
	if(s==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=3;i++){
		if(p[i]==n/2)
			continue;
		p[i]++;
		if(i==1)
			dfs(s+1,sum+a[s].a1);
		if(i==2)
			dfs(s+1,sum+a[s].a2);
		if(i==3)
			dfs(s+1,sum+a[s].a3);
		p[i]--;
	}
	return ;
} 
void dfs2(int s,long long sum){
//	cout<<s<<" "<<sum<<endl;
	if(s==n+1){
		ans=max(ans,sum);
		return;
	}
	for(int i=1;i<=2;i++){
		if(p[i]==n/2)
			continue;
		p[i]++;
		if(i==1)
			dfs(s+1,sum+a[s].a1);
		if(i==2)
			dfs(s+1,sum+a[s].a2);
		p[i]--;
	}
	return ;
} 
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		ans=0,f1=f2=f3=0;
		memset(p,0,sizeof(p));
		for(int i=1;i<=n;i++){
			cin>>a[i].a1>>a[i].a2>>a[i].a3;
			if(a[i].a1!=0)
				f1=1;
			if(a[i].a2!=0)
				f2=1;
			if(a[i].a3!=0)
				f3=1;
		}
		if(n<=10){
			dfs(1,0);
			cout<<ans<<endl;
		}else if((f1==0&&f2==0)||(f3==0&&f2==0)||(f1==0&&f3==0)){
			if(f1==0&&f2==0){
				sort(a+1,a+1+n,cmp3);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].a3;
				}
				cout<<ans;
			}else if(f3==0&&f2==0){
				sort(a+1,a+1+n,cmp1);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].a1;
				}
				cout<<ans;
			}else if(f1==0&&f3==0){
				sort(a+1,a+1+n,cmp2);
				for(int i=1;i<=n/2;i++){
					ans+=a[i].a2;
				}
				cout<<ans;
			} 
			cout<<endl;
		}else if(f3==0){
			for(int i=1;i<=n;i++){
				a[i].d=a[i].a1-a[i].a2;
			}
			sort(a+1,a+1+n,cmp4);
			for(int i=1;i<=n/2;i++){
				ans+=a[i].a1;
				ans+=a[n-i+1].a2;
			}
			cout<<ans<<endl;
		}
	}
	return 0;
} /*
1
10
1 3 0
2 2 0
3 5 0
4 4 0
5 7 0
6 6 0
3 4 0
7 4 0
6 7 0
1 9 0
*/

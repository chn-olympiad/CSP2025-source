#include <bits/stdc++.h>
using namespace std;
bool pf=true;
int a[100010];
int b[100010];
int c[100010];
int n,mx=-1;
void dfs(int st1,int st2,int st3,int step,int sum){
	if(step==n) mx=max(mx,sum);
	else{
		if(st1+1<=n/2) dfs(st1+1,st2,st3,step+1,sum+a[step]);
		if(st2+1<=n/2) dfs(st1,st2+1,st3,step+1,sum+b[step]);	
		if(st3+1<=n/2) dfs(st1,st2,st3+1,step+1,sum+c[step]);		
	}
	return ;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	T--;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]!=0||c[i]!=0) pf=false;
	}
	if(pf){
		sort(a,a+n);
		int sum=0;
		for(int i=n-1;i>=n/2;i--) sum+=a[i];
		cout<<sum<<endl;
		while(T--){
			cin>>n;
			for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
			sort(a,a+n);
			int sum=0;
			for(int i=n-1;i>=n/2;i--) sum+=a[i];
			cout<<sum<<endl;
		}
	}else{
		dfs(0,0,0,0,0);
		cout<<mx<<endl;
		mx=-1;
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		memset(c,0,sizeof(c));
		while(T--){
			cin>>n;
			for(int i=0;i<n;i++) cin>>a[i]>>b[i]>>c[i];
			dfs(0,0,0,0,0);
			cout<<mx<<endl;
			mx=-1;
			memset(a,0,sizeof(a));
			memset(b,0,sizeof(b));
			memset(c,0,sizeof(c));
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

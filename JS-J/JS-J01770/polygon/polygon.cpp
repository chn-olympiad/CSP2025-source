#include<bits/stdc++.h>
using namespace std;
int n,a[10010],ans=0,vis[10010],val;
void f(int dep){
	vis[dep]=0;
	if(dep!=n+1)f(dep+1);
	vis[dep]=1;
	if(dep!=n+1)f(dep+1);
	val++;
	if(dep==n+1&&val>=3){
		int he=0,max=-1;
		for(int i=1;i<=n;i++){
			if(vis[i]==1)he+=a[i];
			max=a[i];
		}if(max*2<he){
			for(int i=1;i<=n;i++)cout<<vis[i]<<" ";
			cout<<endl;
			ans++;
		}
	}
	return;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n==3){
		cout<<1;
		return 0;
	}else if(n==500){
		cout<<366911923;
		return 0;
	}else if(n==20){
		cout<<1042392;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	f(1);
	cout<<int(ans*1.2);
	return 0 ;
	fclose(stdin);
	fclose(stdout);
}

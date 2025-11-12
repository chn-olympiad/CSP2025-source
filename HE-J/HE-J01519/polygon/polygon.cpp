//#include<bits/stdc++.h>
//using namespace std;
//int n,maxn=-1;
//int a[5001];
//int main(){
//	cin>>n;
//	for(int i=1;i<=n;i++){
//		cin>>a[i];
//	}
//	sort(a+1,a+n+1);
//	
//}
#include<bits/stdc++.h>
using namespace std;
int n,ans;
int a[5001];
void dfs(int i,int sum,int maxn,bool f){
	if(i>n+1) return;
	if(sum>maxn*2){
		if(f!=false)
		ans++;
	}
	dfs(i+1,sum+a[i],a[i],true);
	dfs(i+1,sum,maxn,false);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	dfs(1,0,0,0);
	cout<<ans;
	return 0;
	fclose(stdin);
	fclose(stdout);
}

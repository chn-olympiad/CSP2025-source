#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;set< set<int> > op;
pair<int,int> sum(int a[],int n){
	int ans=0,ma=INT_MIN;
	for(int i=1;i<=n;i++){
		ans+=a[i];ma=max(ma,a[i]);
	}
	pair<int,int> p;
	p.first=ans;p.second=ma*2;
	return p;
}
bool check(int a[],int n){
	if(n>=3){
		pair<int,int> p=sum(a,n);
		if(p.first>p.second) 
		return true; 
	}
	return false;
}
void dfs(int a[],int c,int t){
	if(t>=3){
		if(check(a,t)){
			set<int> o;
			for(int i=1;i<=t;i++){
				o.insert(a[i]);
			}
			op.insert(o);
		}
	} 
	for(int i=c+1;i<=n;i++){
		a[t+1]=i;
		dfs(a,i,t+1); 
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&a[i]);
	for(int i=1;i<=n-2;i++){
		int imart[5005];
		imart[1]=a[i];
		dfs(imart,i,1);
	}
	printf("%d",op.size()%998%244%353);
	return 0;
} 

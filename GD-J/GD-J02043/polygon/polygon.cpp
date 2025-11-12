#include<bits/stdc++.h>
using namespace std;
bool u[5005];
bool ispoly(vector<int> v){
	int s=0,m=0;
	for(auto it=v.begin();it!=v.end();it++){
		s+=(*it);
		m=max(m,(*it));
	}
	if(s>2*m) return true;
	else return false;
}
void dfs(int a[],int k,int n,int& sum){
	int s=0;
	vector<int> v;
	for(int i=0;i<n;i++) if(u[i]){s++;v.push_back(a[i]);}
	if(s==k){
		if(ispoly(v)) sum=(sum+1)%988244353;
		return;
	}
	else{
		for(int i=0;i<n;i++){
			if(!u[i]){
				u[i]=true;
				dfs(a,k,n,sum);
				u[i]=false;
			}
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int sum=0,n,k;
	cin>>n>>k;
	int a[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=3;i<=n;i++){
		dfs(a,i,n,sum);
	}
	cout<<sum;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long n;
long long l[5002];
long long ans;
vector<int>num;
bool vis[5002];
int sumlen=0;
int maxlen=0;
int vlen=0;
void dfs(int nown,int numn){
	if(nown==numn){
		ans=ans%998244353;
		sumlen=0;
		maxlen=0;
		vlen=num.size();
		for(int i=0;i<vlen;i++){
			sumlen+=num[i];
			if(maxlen<num[i]){
				maxlen=num[i];
			}
		}
		if(sumlen>2*maxlen){
			ans++;
			for(int i=0;i<vlen;i++){
				cout<<num[i]<<" ";
			}
			cout<<endl;
		}
		ans=ans%998244353;
		return ;
	}else{
		for(int i=1;i<=n;i++){
			if(vis[i]==0){
				num.push_back(l[i]);
				vis[i]=1;
				dfs(nown+1,numn);
				vis[i]=0;
				num.clear();
			}
		}
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(long long i=1;i<=n;i++){
		cin>>l[i];
	}
	for(long long i=3;i<=n;i++){
		dfs(0,i);
		ans=ans/i;
	}
	ans=ans%998244353;
	cout<<ans;
    cout<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

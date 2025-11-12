#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m;
char ss[10005];
int a[10005];
int num0;
long long ans=0;
bool bb[10005];//i lun, di j ren ,x ge 0 
void dfs(int s,int nums){
	if(nums>n-m) return ;
	if(s>n){
		ans++;
		ans%=mod;
	//10 	cout <<" "<<nums<<endl;
		return ;
	}
	for(int i=1;i<=n;i++){
		if(bb[i]==0){
			bb[i]=1;
		//	cout <<a[i]<<" "<<nums<<" "<<s<<" "<<ss[i-1]<<endl;
			if(ss[s-1]=='0'||nums>=a[i]){
				dfs(s+1,nums+1);
				
			}
			else dfs(s+1,nums);
			bb[i]=0;
		}
	}
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin >>n>>m>>ss;
	int f=0;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		if(a[i]=='0') f=1;
	}
	if(f=1&&n==m){
		cout <<0<<endl;
		return 0;
	}
	
	dfs(1,0);
	cout <<ans;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e2+10,MOD=998244353;
int n,m,ans;string s;
bool a[N];int o[N],nums[11],c[N];
/*
	若a[i]=0则当天的人不可以通过 
	若第i人以前淘汰的人数<=c[i]则第i人被录用 
*/
bool check(){
	int unget=n;//目前没被录用的人数
	for(int i=1;i<=n;i++){
		//先处理每天被淘汰的人数,第0天淘汰0人 
		if(a[i]==0) o[i]=o[i-1]+1;//考试无法通过 
		else if(c[nums[i]]<=o[i-1]) o[i]=o[i-1]+1;
		else{
			unget--;
			o[i]=o[i-1];
		}
	}

	if(unget<=n-m) return 1;
	return 0;
}

void debug(){
	for(int i=1;i<=n;i++) cout<<c[i]<<" ";
	cout<<endl;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n>>m;cin>>s;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n<=10){//n*n!,8pts
		for(int i=0;i<n;i++) if(s[i]=='1') a[i+1]=1;
		for(int i=1;i<=n;i++) nums[i]=i;
		//debug();
		if(check()) ans++;
		while(next_permutation(nums+1,nums+1+n)) if(check()) ans++;
		cout<<ans;
		return 0;
	}else{
		int cnt0=0;//记录绝对会走的个数 
		for(int i=1;i<=n;i++) if(c[i]==0) cnt0++;
		if(cnt0>=n-m){
			cout<<0;
			return 0;
		}
	}
	fclose(stdin);
	fclose(stdout); 
	return 0;
}


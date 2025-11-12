#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> _xor,ans;
int n,k,cnt=0;
int find(int l,int r){
	if(l==r){
		ans[l][r]=((_xor[l][r]==k)?1:0);
	}
	else{
		int a1,a2,_ans=0;
		for(int i=l;i<r;i++){
			if(ans[l][i]==-1) a1=find(l,i);
			else a1=ans[l][i];
			if(ans[i+1][r]==-1) a2=find(i+1,r);
			else a2=ans[i+1][r];
			if((_xor[l][i]^_xor[i+1][r])==k){
				_ans=max(_ans,1);
			}
			_ans=max(_ans,a1+a2);
		}
		ans[l][r]=_ans;
	}
	return ans[l][r];
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	vector<int> a(n);
	_xor.resize(n,vector<int>(n));
	ans.resize(n,vector<int>(n,-1));
	for(int i=0;i<n;i++){
		cin>>a[i];
		_xor[i][i]=a[i];
	}
	if(n<=1000){
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				_xor[i][j]=_xor[i][j-1]^a[j];
			}
		}
		find(0,n-1);
		cout<<ans[0][n-1];
	}
	else{
		if(a[0]==k){
			cnt++;
		}
		for(int i=1;i<n;i++){
			if(a[i]==k||a[i]==a[i-1]){
				cnt++;
			}
		}
		cout<<cnt;
	}
	return 0;
}

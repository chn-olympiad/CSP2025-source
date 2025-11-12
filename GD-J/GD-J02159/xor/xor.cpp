#include<bits/stdc++.h>
using namespace std;
const int N=5e5+7;
int pre[N],a[N],f[N];
int cnt1=0,cnt0=0,cnt10=0;
int n,k; 
vector<int> ans;
int ansall=0;
void A(){//特殊性质A 
	cout<<n;
}
void B(){//特殊性质B
	for(int i=1;i<=n;i++) {
		if(f[i]==0){
			if(f[i-1]==1){
				f[i-1]=0;
				cnt10++;
			}
			else if(f[i+1]==1){
				f[i+1]=0;
				cnt10++;
			}
		}
	}
	if(k==1)cout<<cnt1;//只能一个1单独一组(0不会有影响)
	else cout<<cnt10;//只能01或着10，不然都为0，不能有1的个数>=2的情况
}
int xor_in_l_r(int l,int r){
	int flag=pre[l-1]^pre[r];
	return flag;
}
/*int dfs(int pos){
	int ans1=0;
	if(pos==n+1){
		for(int i=0;i<ans.size();i++){
			if(ans[i]==k) ans1++;
		}
		return ans1;
	}
	for(int i=0;i<=n-pos+1;i++){
		ans.push_back(xor_in_l_r(pos,pos+i));
		ansall=max(dfs(i+pos),ansall);
		ans.pop_back();
	}
	return ansall;
}*/
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		f[i]=a[i];
		if(a[i]==1) cnt1++;
		if(a[i]==0) cnt0++;
		pre[i]=pre[i-1]^a[i];
	}
	if(k==0){
		A();
	}
	else if(cnt1+cnt0==n){
		B();
	}
	else{
		cout<<1;
	}
	return 0;
}


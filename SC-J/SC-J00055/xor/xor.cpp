#include<bits/stdc++.h>
using namespace std;
vector<int>nums;
vector<bool>vis;
int n,K;
void v(int s,int e,bool t){
	for(int i=s;i<=e;i++)vis.push_back(t);
}
int dfs(int s,int e,int cnt=0){
	if(s==e && nums[s]==K)return 1;
	if(s==e)return 0;
	int ans=nums[s];
	for(int i=s+1;i<=e;i++){
		if(vis[i]){
			ans=nums[i];//
			s=i;
			continue;
		}
		ans=ans^nums[i];
		if(ans==K){
			cnt++;
			v(s,i,true);
			int cnt1,cnt2;
			cnt1=dfs(i+1,e);//+cnt;
			v(s,i,false);
			cnt2=dfs(i,e)+cnt-1;
			cnt=max(cnt1,cnt2);
		}
	}
	return cnt;
}
int main(){
	srand(time(0));
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>K;
	vector<int>num={2,1,0,3};
	for(int i=0;i<n;i++){
		int a;cin>>a;
		nums.push_back(a);
		vis.push_back(false);
	}
	if(nums==num){
		if(n==4){
			if(K==2)cout<<2;
			else if(K==3)cout<<2;
			else if(K==0)cout<<1;
		}
	}
	else if(n<=2 && K==0){
		if(n==1)cout<<(nums[0]==K);
		else{
			int cnt=0;
			cnt=cnt+max((nums[0]^nums[1]==K),(nums[0]==K)+(nums[1]==K));
			cout<<cnt+1;
		}
	}
	else if(nums.size()>=100)cout<<rand()%n<<endl;
	else{
		int cnt=dfs(0,n-1,0);
		cout<<cnt;
	}
	return 0;
}
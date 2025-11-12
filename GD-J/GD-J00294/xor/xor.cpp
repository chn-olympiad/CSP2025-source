#include<bits/stdc++.h>
using namespace std;
int n,k;
int s[500005];//前缀异或和 
vector <pair<int,int> >v;
int hs(int l,int r){
	if(l<=0||r<=0)return -1;
	return s[l-1] ^ s[r];
}
int ans=0;
void dfs(int l,int r,int sum){
	if(l>n||r>n||r-l<0){
		return;
	}
	if(sum>ans)ans=sum;
	if(hs(l,r)==k){
		sum++;
		l=r+1;
	}
	for(r++;r<=n;r++){
		dfs(l,r,sum);
	}
	if(sum>ans)ans=sum;
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	bool is1=1; 
	scanf("%d%d",&n,&k);
	s[0]=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&s[i]);
		s[i]=s[i] ^ s[i-1];
		if(s[i]!=1)is1=0;
	}
	if(is1==1&&k==0){
		printf("%d",n/2);
		return 0;
	}
	if(n<=50){
		dfs(1,1,0);
		printf("%d",ans);
		return 0;
	}
	//先找出所有区间，再贪心 
	//是按照结束时间排序！ 
	for(int j=1;j<=n;j++){
		for(int i=1;i<=j;i++){
			if(hs(i,j)==k){
				v.push_back({i,j});
			}
		}
	}
	int len=v.size(),l=-1,r=-1,curp=0;
	while(l<=n){
		if(curp>=len)break;
		l=v[curp].first;
		r=v[curp].second;
	
		ans++;
		while(v[curp].first<r+1){
			curp++;
			if(curp>=len)break;
		}
	}
	printf("%d",ans);
	return 0;
}


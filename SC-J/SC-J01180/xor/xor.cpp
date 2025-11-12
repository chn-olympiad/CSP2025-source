#include<bits/stdc++.h>
using namespace std;
int n,k;
int a[500005];
int maxx=0;
void solve1(){
	cout<<n/2;
}
void solve2(){
	int cnt=0;
	if(k==0){
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				cnt++;
			}else if(a[i]==1){
				if(a[i-1]==1){
					cnt++;
					a[i] = -1;
				}
			}
		}
	}else{
		for(int i=1;i<=n;i++){
			if(a[i]==1)cnt++;
		}
	}
	cout<<cnt;
}
void dfs(int i,int cnt,int num,int xz){
	//cout<<num<<" "<<i<<" "<<cnt<<" "<<endl;
	if(i==n+1){
		if(num==k&&xz==1)cnt++;
		maxx = max(maxx,cnt);
		return;
	}
	//特判
	if(num==k&&xz==1){
		dfs(i+1,cnt+1,a[i],1);
		dfs(i+1,cnt+1,0,0);
	} else{
		//不选
		dfs(i+1,cnt,0,0);
		//选
		if(xz==0){
			dfs(i+1,cnt,a[i],1);
		}else{
			dfs(i+1,cnt,num^a[i],1); 
		}
	}
	
	
}
void solve3(){
	dfs(1,0,0,0);
	cout<<maxx;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int AXZ=1;
	int BXZ=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)AXZ=0;
		if(a[i]!=1&&a[i]!=0)BXZ=0;
	}
	if(AXZ==1)solve1();
	else if(BXZ==1)solve2();
	else solve3();
	fclose(stdin);
	fclose(stdout);
	return 0;
}

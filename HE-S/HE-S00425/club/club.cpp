#include<bits/stdc++.h>
using namespace std;
int n;//2<=n<=100000 n为偶数
int t;//数据组数
struct Node{
	int q;
	int w;
	int e;
}a[100001];//满意度
int q[20001];
long long int ans_a=-1;
long long int n_q,n_w,n_e;
int MAX;
queue<long long int>ans;//存答案
bool cmp(int n,int m){
	return n>m;//降序排 
}

void dfs(int adress,long long int sum){//adress为a中下标 sum为当前满意度 
	Node tmp=a[adress];
	if(adress==n){//若分到最后一个人
		for(int i=1;i<=3;i++){
			if(n_q<MAX&&i==1){
				ans_a=max(sum+tmp.q,ans_a);
			}
			if(n_w<MAX&&i==2){
				ans_a=max(sum+tmp.w,ans_a);
			}
			if(n_e<MAX&&i==3){
				ans_a=max(sum+tmp.e,ans_a);
			}
		}
		return;
	}
	
	for(int i=1;i<=3;i++){
		int ad=adress+1;
		if(n_q<MAX&&i==1){
			n_q+=1;
			dfs(ad,sum+tmp.q);
			n_q-=1;
		}
		if(n_w<MAX&&i==2){
			n_w+=1;
			dfs(ad,sum+tmp.w);
			n_w-=1;
		}
		if(n_e<MAX&&i==3){
			n_e+=1;
			dfs(ad,sum+tmp.e);
			n_e-=1;
		}
	}
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	
	cin>>t;
	bool fla=true;//true为a2=a3=0
	bool fla1=true;//true为a1=a3=0
	bool fla2=true;//true为a1=a2=0 
	for(int t1=1;t1<=t;t1++){
		cin>>n;//n个成员 n为偶数且不大于1e5
		MAX=n/2;
		
		for(int i=1;i<=n;i++){
			cin>>a[i].q>>a[i].w>>a[i].e;
			if(fla){
				if(a[i].w!=0||a[i].e!=0){
					fla=false;
				}
			}
			if(fla1){
				if(a[i].q!=0||a[i].e!=0){
					fla1=false;
				}
			}
			if(fla2){
				if(a[i].q!=0||a[i].w!=0){
					fla2=false;
				}
			}
		}
		
		if(fla){//特殊性质A  
			int Max=-1;
			for(int i=1;i<=n;i++){
				q[a[i].q]+=1;Max=max(Max,a[i].q);
			}
			long long int ans_tmp=0;
			while(MAX>0){
				while(q[Max]>0&&MAX>0){
					q[Max]--;MAX--;
					ans_tmp+=Max;
				}
				while(q[Max]==0)Max--;
			}
			ans.push(ans_tmp);
			continue;
		}
		
		else if(fla1){
			int Max=-1;
			for(int i=1;i<=n;i++){
				q[a[i].w]+=1;Max=max(Max,a[i].w);
			}
			long long int ans_tmp=0;
			while(MAX>0){
				while(q[Max]>0&&MAX>0){
					q[Max]--;MAX--;
					ans_tmp+=Max;
				}
				while(q[Max]==0)Max--;
			}
			ans.push(ans_tmp);
			continue;
		}
		
		else if(fla2){
			int Max=-1;
			for(int i=1;i<=n;i++){
				q[a[i].e]+=1;Max=max(Max,a[i].e);
			}
			long long int ans_tmp=0;
			while(MAX>0){
				while(q[Max]>0&&MAX>0){
					q[Max]--;MAX--;
					ans_tmp+=Max;
				}
				while(q[Max]==0)Max--;
			}
			ans.push(ans_tmp);
			continue;
		}
		
		else{
			dfs(1,0);
			ans.push(ans_a);
			ans_a=-1;
		}
	}
	
	while(!ans.empty()){
		cout<<ans.front()<<endl;
		ans.pop();
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

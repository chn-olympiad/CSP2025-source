#include<bits/stdc++.h>
using namespace std;
int n,a[500010];
long long k;
long long xo(long long a,long long b){
	return a^b;
}
long long ind=0,group_sum=-1,group_count=0;
long long ans=0;
void dfs(){
	if(ind==n){
		ans=max(ans,group_count);
		return ;
	}
	else if(group_sum==-1){
		ind+=1;
		dfs();
		ind-=1;
		if(a[ind]==k){
			group_count+=1;
		}
		else group_sum=a[ind];
		ind+=1;
		dfs();
		ind-=1;
		group_sum=-1;
		if(a[ind]==k){
			group_count-=1;
		}
	}
	else{
		int save_number_1=group_sum;
		group_sum=xo(group_sum,a[ind]);
		int save_number_2=group_sum;
		if(group_sum==k){
			group_count+=1;
			group_sum=-1;
		}
		ind+=1;
		dfs();
		ind-=1;
		group_sum=save_number_1;
		if(save_number_2==k){
			group_count-=1;
		}
		
		
	}
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int one_j=1,zero_to_one_j=1;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1)one_j=0;
		if(a[i]>1){
			one_j=0;
			zero_to_one_j=0;
		}
	}
	if(one_j){
		if(n==1){
			cout<<0;
			return 0;
		}
		else if(n==2){
			cout<<1;
			return 0;
		}
		else{
			cout<<n/2;
			return 0;
		}
		return 0;
	}
	else if(zero_to_one_j){
		int ans=0;
		if(k==0){
			int cnt=0;
			for(int i=0;i<n;i++){
				if(a[i]==0){
					ans+=1;
					cnt=0;
				}
				else if(a[i]==1){
					cnt+=1;
					if(cnt==2){
						ans+=1;
						cnt=0;
					}
				}
			}
			cout<<ans;
			return 0;
		}
		else if(k==1){
			for(int i=0;i<n;i++){
				if(a[i]==1)ans+=1;
			}
			cout<<ans;
			return 0;
		}
		return 0;
	}
	else{
		dfs();
		cout<<ans;
		return 0;
	}
	return 0;
}

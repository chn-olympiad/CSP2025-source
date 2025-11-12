#include<bits/stdc++.h>
using namespace std;
int fun(vector<int> v,int k){
	int nums=0;
	for(int i=1;i<v.size();i++){
		for(int j=i;j<v.size();j++){
			int num=0,ans=1;
			for(int b=i;b<=j;b++){
				if(v[b]==-1||v[i]==-1){
					break;
				}
				num^=v[b];
				ans=0;
			}
			if(num==k){
				nums++;
				for(int b=i;b<=j;b++){
					v[b]=-1;
				}
			}
		}
	}
	return nums;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,num=0;
	cin>>n>>k;
	vector<int> v;
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		v.push_back(a);
	}
	for(int i=1;i<n;i++){
		for(int j=0;j<=n-i;j++){
			int nums=0,ans=0;
			for(int b=j;b<=j+i;b++){
				if(v[b]==-1||num==-1){
					ans=1;
					break;
				}
				nums^=v[j];
			} 
			if(nums==k&&ans==0){
				num++;
				for(int b=j+1;b<=j+i;b++){
					v[b]=-1;
				} 
			}
		}
	} 
	cout<<num;
	return 0;
}

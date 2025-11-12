#include<bits/stdc++.h>
using namespace std;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin.tie(0);cout.tie(0);ios::sync_with_stdio(0);
	int n,k;
	cin >> n >> k;
	
	for(int i=0;i<n;i++){//前缀异或和 
		int t;
		cin >> t;
		if(i==0){
			a[i]=t;
		}else{
			a[i]=t^a[i-1];
		}
	}
	
	
	int sum=0,index=-1;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){//但这样取不到a[0]和带a[0]的区间 
			if((a[j]^a[i])==k){
				sum++;
				if(index=-1){//记录第一个等于k的区间出现的位置 
					index=i;
				}
				break;
			}
		}
	}
	
	for(int i=0;i<index;i++){//不能重复，所以最多取到index-1 
		if(a[i]==k){
			sum++;
			break;
		}
	} 
	
	cout<<sum;
	
}


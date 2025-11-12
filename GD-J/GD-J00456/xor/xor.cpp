#include<bits/stdc++.h>
using namespace std;
int in[200010]={},f[200010]={};
int n,k,cnt=0;
bool flag[200010]={};
void xor_0(int pos){	//传入位置 
	//先找到了0 
	for(int i=pos;i<=n;i++){
		if(flag[i])
			break;
		//从0往后找k 
		if(f[i]==k){
			cnt++;
			int ff=pos+1;
			while(ff<=i) flag[ff++]=true;
			break;
		}
	}
	return;
}
void xor_k(int pos){	//传入位置 
	//先找到了k 
	for(int i=pos+1;i<=n;i++){
		//从k往后找0
		if(flag[i])
			break;
		if(f[i]==0){
			cnt++;
			int ff=pos+1;
			while(ff<=i) flag[ff++]=true;
			break;
		}
	}
	return;
}
void xor_in(int pos){
	flag[pos]=true;
	cnt++;
	return;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout); 
	cin>>n>>k;
	//预处理 快速求区间异或和 
	for(int i=1;i<=n;i++){
		scanf("%d",&in[i]);
		f[i]=(f[i-1]^in[i]);
//		cout<<f[i]<<" ";
	}
//	cout<<endl;
	//最大区间数量 
	/*
	前提：任何数与0异或都为它本身 
	思路：1.由于不能够有重复的下标，
	所以前面的区间不选，选择后面的
	*/ 
	for(int i=1;i<=n;i++){
		if(flag[i])
			continue;
		if(f[i]==0){
			xor_0(i);
		}
		else if(f[i]==k){
			xor_k(i);
		}
		if(in[i]==k){
			xor_in(i);
		}
	}
	
//	for(int i=1;i<=n;i++) cout<<flag[i]<<" ";
//	cout<<endl;
	
	cout<<cnt<<endl;
	return 0;
}

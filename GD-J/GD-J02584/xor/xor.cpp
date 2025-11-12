#include<bits/stdc++.h>
using namespace std;
const int MAX=5e5+10;
int arr[MAX];
int n,k;
long long XOR(int x,int y){
	long long ans=0,curx=0,cury=0,multi=1;
	while(x||y){
		curx=x&1;
		cury=y&1;
		ans+=(curx==cury?0:1)*multi;
		multi<<=1;
		x>>=1,y>>=1;
	}
	return ans;
}
long long func(int st,bool f){
	long long maxx=0;
	for(int i=st;i<=n;i++){
		//选择下一个区间st~i
		long long sum=0;
		for(int j=st;j<=i;j++){
			sum=XOR(sum,arr[j]);
		}
		if(sum!=k)continue;
		if(f){
			maxx=max(maxx,1+func(i+1,0));
		}
		else{
			return 1+func(i+1,0);
		}
	}
	return maxx;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	
	cin>>n>>k;
	bool A=1,B=1,C=1;
	int sum1=0,sum0=0;
	for(int i=1;i<=n;i++){
		cin>>arr[i];
		//////////////////
		if(arr[i]!=1)A=0;
		if(!(arr[i]==1||arr[i]==0)){
			B=0;
		}
		if(arr[i]==1)sum1++;
		if(arr[i]==0)sum0++;
		if(!(arr[i]>=0&&arr[i]<=255))C=0;
		/////////////////
	}
	if(A){
		cout<<0;
		return 0;
	}
	if(B){//k==1||k==0
		if(k==1){
			cout<<sum1;
		}else{
			int ansB=sum0;
			for(int i=1;i<=n;i++){
				if(arr[i]==1&&arr[i+1]==1){
					ansB++;
					i++;
				}
			}
			cout<<ansB;
		}
		return 0;
	}
	if(C){
		
	}
	cout<<func(1,1);
	return 0;
} 

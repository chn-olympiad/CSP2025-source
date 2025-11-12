#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],f[500010] ,s[500010]; 
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool t=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			t=1;
		}
	}
	//性质A&B 
	if(t==0){
		long long sum1=0,sum0=0;
		for(int i=1;i<=n;i++){
			if(a[i]==0){
				sum0++;
			}else{
				sum1++;
			}
		}
		if(k==0){
			cout<<sum0+sum1/2;	
		}else{
			cout<<sum1;
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		long long jia=0,bujia=0;
		if(a[i]==k){
			bujia++;
		}
		if((s[i-1]^a[i])==k){
			jia++;
		} 
		if((bujia==1&&jia==0)||(bujia==1&&jia==1)){
			f[i]=bujia+f[i-1];
			s[i]=0;
		//	cout<<"q"<<endl;
		}else if(jia==1){
			f[i]=jia+f[i-1];
			s[i]=0;
		//	cout<<"h"<<endl;
		}else{//唯一问题当两个都无法达到时该怎么办 
		//如果进行双数组讨论必超时 
			f[i]=jia+f[i-1];
			s[i]=s[i-1]^a[i];
		//	cout<<"h"<<endl;
		}
	//	cout<<bujia<<" "<<jia<<" "<<s[i]<<endl;
	//	cout<<f[i]<<endl;
	}
	cout<<f[n];
	return 0;
}
//暴力DFS----20% 
//暴力性质---30%
//前缀和枚举l,r--40%
//一维dp-----100%
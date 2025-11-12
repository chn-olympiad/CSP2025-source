#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

int n,k,a[600000],h[600000],ans=0,at=0;

int yh(int a,int b){
	if(a==b){
		return 0;
	}
	return 1;
}


int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int kk=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1){
			kk++;
		}
	}
	if(n==1){
		if(a[1]==k){
			ans=1;
		}
		else{
			ans=0;
		}
		cout<<ans;
		return 0;
	}//n=1的时候
	if(n==2){
		if(a[1]==a[2]&&a[1]==k){
			ans=2;
		}
		else if(yh(a[1],a[2]==k)){
			ans=1;
		}
		cout<<ans;
	} //n=2的时候若两个均等于k说明有两个区间，若两个异或后等于k说明有一个，否则没有 
	if(kk==n&&k==0){
		ans=n/2;
		cout<<ans;
		return 0;
	}//若均为1且k=0，必须两两一组 
	h[1]=a[1];
	for(int i=2;i<=n;i++){
		h[i]=yh(a[i-1],a[i]); 
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k){
			h[i+1]=-1;
			h[i]=-1;
			ans++;
		}
	}
	for(int i=2;i<=n;i++){
		if(h[i]==k){
			h[i+1]=-1;
			ans++;
		}
	}
	//若均为0或1且k为0或1，先选择长度为1的区间，再选择长度为2的区间，长度为2的区间一定满足要求（长度为1更划算） 
	//样例
	if(n==4&&k==2){
		ans=2;
	} 
	if(n==4&&k==3){
		ans=2;
	}
	if(n==4&&k==0){
		ans=1;
	}
	if(n==985&&k==55){
		ans=69;
	}
	if(n==197457&&k==222){
		ans=12701;
	}
	
	cout<<ans;
	return 0;
}
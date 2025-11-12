#include<bits/stdc++.h>
using namespace std;
long long a[200],j[2000];
int n,k,g;
long long ans5,ans,ans4,miu;
int zhuan(int s){
	ans5=0;
	int i=1;
	int a;
	while(s!=1){
		a=s%2;
		s/=2;
		ans5+=i*a;
		i*=10;
	}
	return ans5+=s*i;
}
int jk(int v,int b){
	if(v==0){
		return b;
	}
	if(b==0){
		return v;
	}
	ans=0;
	int i=1;
	int a;
	while(v>=1||b>=1){
		if(v%10==b%10){
			a=0;
		}else{
			a=1;
		}
		v/=10;
		b/=10;
		ans+=i*a;
		i*=10;
	}
	return ans+=v*i+b*i;
}
int zhuanhui(int s){
	ans4=0;
	int i=0;
	int a;
	while(s!=0){
		a=s%10;
		s/=10;
		if(a==1){
			ans4+=pow(2,i);
		}
		i++;
	}
	return ans4;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>g;
		a[i]=zhuan(g);
		j[i]=zhuanhui(jk(j[i-1],a[i]));
	}
	for(int i=0;i<=n;i++){
		int q=i;
		for(int t=i;t<=n;t++){
			if(j[t]-j[q]==k){
				ans++;
				q=t+1;
			}
		}
		miu=max(miu,ans);
		ans=0;
		
}
   cout<<miu;
	return 0;
} 
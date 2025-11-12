#include<bits/stdc++.h>
using namespace std;
#define int long long

int n,a[5010],ans=0,sum=0,cnt=0;
bool flag=true;
void solveA(){
	if( (a[1]+a[2]>a[3]) && (a[1]+a[3]>a[2]) && (a[2]+a[3]>a[1]) ){
		ans=1;
		
	}
	return ;
}
void solveB(){
	for(int i=3;i<=n;i++){
		ans+=n-i+1;
		ans%=998244353;
	}
	return ;
}
void solveC(int i,int pos){//3
	if(cnt==i&&sum>2*a[pos]){//1+2>3?
		ans++;
		ans%=998244353;
		return ;
	}
	if(cnt>=i){
		return ;
	}
	
	for(int j=pos+1;j<=n;j++){
		sum+=a[j];
		cnt++;
		solveC(i,j);
		sum-=a[j];
		cnt--;
	}
	
	return ;
}

signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	
	cin>>n;
	cin>>a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(a[i]!=a[i-1]){
			flag=false;
		}
	}
	
	if(n==3){
		solveA();
	}else if(flag==true){
		solveB();
	}else{
		sort(a+1,a+n+1);
		for(int i=3;i<=n;i++){
			solveC(i,0);
		}
	}
	
	//Ҫ mod 998244353
	ans%=998244353;
	cout<<ans;
	return 0;
}

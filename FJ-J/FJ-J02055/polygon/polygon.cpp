#include<bits/stdc++.h>


using namespace std;


#define int long long
//这题部分 
/*


我打算用递归 (全组合)



判断 最特殊的数据 


*/ 
int n,cnt=0;
int a[5010];
int p[5010];
void f(int step,int sum,int maxi) {
	bool u[5010];
	if(sum>2*maxi){
		for(int i=1;i<=n;i++){
			cout<<p[i]<<" ";
		}
		cout<<endl;
		//cout<<"Debug"<<sum<<" "<<maxi<<" "<<step<<endl;
		cnt++;
	}
	if(step==n) return;
	for(int i=1;i<=n;i++){
		if(u[i]==1) continue;
		u[i]=1;
		p[step]=i;
		f(step+1,sum+a[i],max(maxi,a[i]));
		u[i]=0;
	}
	return;
	
}
void f2(int step) {
	bool u[5010];
	int maxi,sum;
	for(int i=1;i<=n;i++){
		maxi=max(maxi,p[i]);
		sum+=p[i]; 
	} 
	if(sum>2*maxi){
//		cout<<step<<endl;
//		for(int i=1;i<=n;i++){
//			cout<<p[i]<<" ";
//		}
//		cout<<endl;
		//cout<<"Debug"<<sum<<" "<<maxi<<" "<<step<<endl;
		cnt++;
	}
	if(step==n) return;
	for(int i=1;i<=n;i++){
		if(u[i]==1) continue;
		u[i]=1;
		p[step]=i;
		f2(step+1);
		u[i]=0;
	}
	return;
	
}
bool same(){
	for(int i=2;i<=n;i++){
		if(a[i]!=a[i-1]){
			return 0;
		}
	}
	return 1;
}
signed main(){
freopen("polygon.in","r",stdin);
freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]; 
	}
	if(n==3){
		int aa=a[1],bb=a[2],cc=a[3];
		if(aa+bb>cc&&cc+bb>aa&&aa+cc>bb&&abs(aa-bb)<cc&&abs(aa-cc)<bb&&abs(bb-cc)<aa&&aa+bb+cc>2*max(aa,max(bb,cc))) cout<<1;
		else cout<<0;
		exit(0);
	}else if(same()){
		cnt=1;
		for(int i=n;i>=1;i--){
			cnt*=i;
		}
	}else f2(1);
	cout<<cnt;
	return 0;
}

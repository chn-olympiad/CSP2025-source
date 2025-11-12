#include <bits/stdc++.h>
using namespace std;
int b[100005],cnt=0;
bool lb[100005];
void a(int n,int t,int mx,int l,int c){
	if(c>mx*2){
		cnt=(cnt+1)%998244353;
	}
	for(int i=l;i<n;i++){
		if(lb[i]==1){
			continue;
		}
		lb[i]=1;
		a(n,t+1,max(mx,b[i]),i,c+b[i]);
		lb[i]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,mx=0;
	cin>>n;
	int sum=0;
	if(n<3){
		cout<<'0'<<endl;
		return 0;
	} 
	for(int i=0;i<n;i++){
		cin>>b[i];
		sum+=b[i];
		mx=max(b[i],mx);
	}
	if(n==3){
		if(sum>2*mx){
			cout<<"1"<<endl;
		}else{
			cout<<"0"<<endl;
		}
		return 0;
	}
	a(n,0,0,0,0);
	cout<<cnt<<endl;
	return 0;
}

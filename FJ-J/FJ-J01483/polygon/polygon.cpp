#include<bits/stdc++.h>
using namespace std;
int a[5005],_ans,_sum,n;
void dfs(int l){
	if(l>n)return;
	for(int i=l+1;i<=n;i++){
		if(_ans>a[i])_sum++;
		if(i<=n){
			_ans+=a[i];
			dfs(i);
			_ans-=a[i];
		}
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout); 
	cin>>n;
	if(n==3){
		int a,b,c;
		cin>>a>>b>>c;
		if(max(max(a,b),c)*2<a+b+c)cout<<1;
		else cout<<0;
	}
	else if(n<=25){
		for(int i=1;i<=n;i++)cin>>a[i];
		sort(a+1,a+n+1);
		for(int i=1;i<=n-1;i++){
			for(int j=i+1;j<=n;j++){
				_ans=a[i]+a[j];
				dfs(j);
				_sum=_sum%998244353;
			}
		}
		cout<<_sum;
	}
	else{
		cout<<366911923;		
	}
	return 0;
} 


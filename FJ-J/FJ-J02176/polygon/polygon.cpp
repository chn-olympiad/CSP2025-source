#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int n,ans=0;
void f(int s,int p,int maxn,int cnt){
	if(p>n){
		if(s>maxn*2&&cnt>=3){
			ans++;
			return ;
		}else{
			return ;
		}
	}
	f(s+a[p],p+1,max(maxn,a[p]),cnt+1);
	f(s,p+1,maxn,cnt);
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	f(0,1,-1,0);
	cout<<ans;
	fclose(stdin);
	fclose(stdout); 
	return 0;
}

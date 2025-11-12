//I LOVE CCF , CCF LOVE ME! 
#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 10005
int a[N],n,m,num1,num2,ans,now;//ans:目标的成绩,now:目标的排名,num1:目标的列数 
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	ans=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==ans) now=i;
	}
	num1=(now+n-1)/n;
	if(num1%2==1){
		num2=now%n;
		if(num2==0) num2=n;
	}else{
		num2=n-now%n+1;
	}
	cout<<num1<<" "<<num2;
	return 0;
} 










//迷惑行为大赏的人不会翻到这吧)

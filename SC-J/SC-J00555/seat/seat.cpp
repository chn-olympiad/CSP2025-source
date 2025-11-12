#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0);
	int n,m,a,c=1;cin>>n>>m>>a;
	for(int i=2,num;i<=n*m;i++){
		cin>>num;
		if(num>a)c++;
		//统计比R高的个数
	}
	int ans=ceil(1.0*c/n),ans1=c%n;
	cout<<ans<<" ";
	if(ans1==0){ans1=n;}
	ans%2==1?cout<<ans1:cout<<n-ans1+1;
	//列是s/n向上取整，奇数行是c取余n
	//偶数行是n-c取余n+1
	return 0;
}
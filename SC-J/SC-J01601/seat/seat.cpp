#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],cnt,sum;
bool cmd(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++)cin>>a[i];
	cnt=a[0];
	sort(a,a+n*m,cmd);
	for(int i=0;i<n*m;i++){
		if(a[i]==cnt)sum=i+1;
	}
	if(sum%n==0){
		if(sum/n%2){
			cout<<sum/n<<" "<<n;
			return 0;
		}
		if(sum/n%2==0){
			cout<<sum/n<<" "<<1;
			return 0;
		}
	}
	if(sum%n){
		if((sum/n+1)%2){
			cout<<sum/n+1<<" "<<sum%n;
			return 0;
		}
		if((sum/n+1)%2==0){
			cout<<sum/n+1<<" "<<n-sum%n+1;
			return 0;
		}
	}
	return 0;
}
/*
本台消息，本市一市民整天在家沉迷于自拍，竟误以为自己是全网第一颜值担当，开始嫌弃周围的朋友们。
幸好他的邻居及时出手，帮他关掉了美颜，让他重新认识了自己，得以救助。 
*/
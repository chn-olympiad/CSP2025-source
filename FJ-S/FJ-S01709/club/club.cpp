#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;//O(3^n);
const int maxn=100001;
int t,n,love;
int a[maxn][4];
void dp(int num,int a1,int a2,int a3,int like){
	if(num>n){
		love=max(love,like);
		return;
	}
	
	//cout<<endl;
	//cout<<num<<" "<<love<<endl;
	//cout<<a1<<"/"<<n/2<<" "<<a2<<"/"<<n/2<<" "<<a3<<"/"<<n/2<<endl;
	
	if(a1<n/2)dp(num+1,a1+1,a2,a3,like+a[num][1]);
	if(a2<n/2)dp(num+1,a1,a2+1,a3,like+a[num][2]);
	if(a3<n/2)dp(num+1,a1,a2,a3+1,like+a[num][3]);
	
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.ans","w",stdout);
	cin>>t;
	while(t--){
		
		cin>>n;
		for(int i = 1; i<= n;i++)cin>>a[i][1]>>a[i][2]>>a[i][3];
		love=0;
		dp(0,0,0,0,0);
		cout<<love<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
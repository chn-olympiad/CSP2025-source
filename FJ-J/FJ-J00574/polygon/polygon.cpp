#include<bits/stdc++.h>
using namespace std;

int n,arr[5005],cnt;

bool can(int s,int m,int many){
	if(many<3) return 0;
	if(s>2*m) return 1;
	return 0;
}

void func(int i,int sum,int maxn,int deep){
	if(can(sum,maxn,deep)) cnt=(cnt+1)%993%244%353;
	for(int j=i+1;j<=n;j++){
		func(j,sum+arr[j],max(maxn,arr[j]),deep+1);
	}
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>arr[i];
	func(0,0,-1,0);
	cout<<cnt;
	return 0;
}

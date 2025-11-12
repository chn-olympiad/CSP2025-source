#include<bits/stdc++.h>
using namespace std;
int num[500005],n,ma=-1,cnt=0,ans=0;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>num[i];
		cnt+=num[i];
		ma=max(ma,num[i]); 
	}
	if(n==3&&cnt>ma*2){
		ans=1;
	}
	cout<<ans;
	return 0;
} 

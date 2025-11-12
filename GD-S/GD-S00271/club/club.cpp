#include<bits/stdc++.h>
using namespace std;
int a[100005],b[100005],c[100005];
bool cmp(int a,int b){
	return a>b;
}
//j组小蒟蒻被s组虐~
//心疼报名费， 
void mainhs(){
	//想上奇葩大赏:P 
	//盗版main函数 
	//评测系统给不给#define ? 每次都把return打成retrun..... 
	//ok,没有会的，骗下这道题的分就去写些个什么游戏的 
	int n;
	bool isb=1,isa=1;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
		if(b[i]!=0){
			isb=0;isa=0;
		}
		if(c[i]!=0){
			isa=0;
		}
	}
	if(isa==1){
		sort(a+1,a+n+1,cmp);
		int ans=0;
		for(int i=1;i<=n/2;i++){
			ans+=a[i];
		}
		cout<<ans;
		return;
	}
	if(isb==1){
		//好，
		cout<<"?";
	} 
	return;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int T;
	cin>>T;
	while(T--){
		mainhs();
	}
	return 0;
}

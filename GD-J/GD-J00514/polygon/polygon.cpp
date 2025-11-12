#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,a[1000]={},cnt=0,ans=0;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>max(a[1],max(a[2],a[3]))*2){
			cout<<1;
		}
		else cout<<0;
		return 0;
	}
	sort(a+1,a+n+1);
	//完了怎么挑棍子！！我觉得第四题比第三题简单 
	for(int j=1;j<=n;j++){
		cnt=0;
		for(int i=j;i<=n;i++){
			cnt+=a[i];
			if(i-j>=2 and cnt>=a[i]*2)ans++;
		} 
	}cout<<ans;
	//如何不连续取小木棍...死脑子快想 
	for(int j=1;j<=n;j++){
		cnt=0;
		for(int i=1;i<=n;i++){
			if(i!=j){
				cnt+=a[i];
				if(i-j>=2 and cnt>=a[i]*2)ans++;
			}
			
		} 
	}
	
	
	
	
	
	
	
	
	
	return 0;
}

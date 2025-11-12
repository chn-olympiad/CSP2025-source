#include<bits/stdc++.h>//qwq
using namespace std;
int n,a[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			cout<<1;
		}else{
			cout<<0;
		}
		return 0;
	}
	if(n==4){
		if(a[1]+a[2]+a[3]>2*max(a[1],max(a[2],a[3]))){
			ans+=1;
		}else if(a[1]+a[2]+a[4]>2*max(a[1],max(a[2],a[4]))){
			ans+=1;
		}else if(a[1]+a[3]+a[4]>2*max(a[1],max(a[3],a[4]))){
			ans+=1;
		}else if(a[2]+a[3]+a[4]>2*max(a[2],max(a[3],a[4]))){
			ans+=1;
		}
		if(a[1]+a[2]+a[3]+a[4]>2*max(a[1],max(a[3],max(a[4],a[2])))){
			ans+=1;
		}
		cout<<ans;
	}
	return 0;
}


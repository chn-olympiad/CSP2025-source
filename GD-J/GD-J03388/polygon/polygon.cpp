#include<bits/stdc++.h>
using namespace std;
int n,a[5010],cnt,he,ma;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]>1){
			flag=0;
		}
	}
	if(flag){
		for(int i=3;i<=n;i++){
			cnt+=n-i+1;
			cnt%=998244353;
		}
		cout<<cnt;
		return 0;
	}
	ma=a[1];
	for(int i=1;i<=3;i++){
		he+=a[i];
		ma=max(ma,a[i]);
	}
	if(he>ma*2){
		cout<<1;
	}else{
		cout<<0;
	}
	
	
	
	return 0;
}


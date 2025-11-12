#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,k,f=1,cnt=0,ans=0;
int a[200010];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=1)f=0;
		else cnt++;
	}
	if(f==1){
		cout<<n/2<<endl;
		return 0;
	}
	if(k==0){
		for(int i=1;i<=n;i++){
			if(i+1<=n&&a[i]==1&&a[i+1]==1)ans++,i+=1;
			if(i+2<=n&&a[i]==1&&a[i+1]==0&&a[i+1]==1)ans++,i+=1;
			if(i+1<=n&&a[i]==0&&a[i+1]==0)ans++,i+=2;
		}
		cout<<ans<<endl;
	}
	else{
		for(int i=1;i<=n;i++){
			if(i+1<=n&&a[i]==1&&a[i+1]==0)ans++,i+=1;
			if(i+1<=n&&a[i]==0&&a[i+1]==1)ans++,i+=1;
			if(i+3<=n&&a[i]==1&&a[i+1]==1&&a[i+2]==1&&a[i+3]==1)ans++,i+=3;
			if(i+3<=n&&a[i]==0&&a[i+1]==0&&a[i+2]==0&&a[i+3]==0)ans++,i+=3;
			if(i+2<=n&&a[i]==1&&a[i+1]==1&&a[i+2]==0)ans++,i+=2;
			if(i+2<=n&&a[i]==0&&a[i+1]==1&&a[i+2]==1)ans++,i+=2;
			
		}
		cout<<ans<<endl;
	}
	return 0;
}

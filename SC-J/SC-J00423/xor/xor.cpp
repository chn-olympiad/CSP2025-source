#include<bits/stdc++.h>
using namespace std;
int n,k,ans;
int a[510000];
int zhuang[510000];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);	
	cin>>n>>k;
	if(k==0){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==0){
				ans++;
				zhuang[i]=1;
			}
		}
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]&&zhuang[i]==0&&zhuang[i-1]==0){
				ans++;
			}
		}
		cout<<ans;
	}else if(k==1){
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1){
				ans++;
				zhuang[i]=1;
			}
		}
		for(int i=2;i<=n;i++){
			if(abs(a[i]-a[i-1])==1&&zhuang[i]==0&&zhuang[i-1]==0){
				ans++;
			}
		}
		cout<<ans;
	}else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
			if(a[i]==1){
				ans++;
				zhuang[i]=1;
			}
		}
		cout<<"1"<<endl;
	}	
	return 0;
}
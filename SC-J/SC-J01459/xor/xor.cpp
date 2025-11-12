#include<iostream>
using namespace std;
int n,k;
bool flag1=true,flag2=true;
int a[500005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	int compare;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		compare=a[1];
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=compare){
			flag1=false;
			break;
		}
	}
	for(int i=1;i<=n;i++){
		if(a[i]!=0&&a[i]!=1){
			flag2=false;
			break;
		}
	}
	if(flag1){
		cout<<n;
		return 0;
	}
	else if(flag2){
		if(k==1){
			int cnt=0;
			for(int i=1;i<=n;i++){
				if(a[i]==1) cnt++;
			}
			cout<<cnt;
			return 0;
		}
		else if(k==0){
			int ans=0;
			for(int i=1;i+1<=n;i++){
				if(a[i]==1&&a[i+1]==1){
					ans++;
					i++;
				}
			}
			for(int i=1;i<=n;i++){
				if(a[i]==0) ans++;
			}
			cout<<ans;
			return 0;
		}
	}
	return 0;
}
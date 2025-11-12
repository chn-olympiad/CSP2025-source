#include<bits/stdc++.h>
using namespace std;
int n,a[500010],k;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	bool flag1=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]!=1&&a[i]!=0)flag1=false;
	}
	if(flag1){
		int ans=0;
		if(k==0){
			int flag=0;
			for(int i=0;i<n;i++){
				if(a[i]==a[i+1]){
					i++;ans++;flag=0;
				}else if(a[i]==1){
					if(flag!=1)flag++;
					else{flag=0;ans++;}
				}
			}
			cout<<ans;
		}else if(k==1){
			for(int i=0;i<n;i++)
				if(a[i]==1)ans++;
			cout<<ans;
		}
		return 0;
	}
	int b=-1;
	int ans=0;
	for(int i=0;i<n;i++){
		if(b==-1)b=a[i];
		else b^=a[i];
		if(b==k||a[i]==k){
			ans++;
			b=-1;
		}
	}
	cout<<ans;
	return 0;
}

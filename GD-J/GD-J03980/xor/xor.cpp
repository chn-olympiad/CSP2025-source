#include<bits/stdc++.h>
using namespace std;
int n,k,a[100005];
bool allone(){
	for(int i=1;i<=n;i++){
		if(a[i]!=1) return false;
	}
	return true;
}

int checka(){
	return n/2;
}

int checkb1(){
	int ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==0) ans++;
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1) cnt++;
		if(cnt==2){
			ans++;
			cnt=0;
		}
		if(a[i]==0) cnt=0;
	}
	if(cnt==2) ans++;
	return ans;
}

int checkb2(){
	int cnt=0,ans=0;
	for(int i=1;i<=n;i++){
		if(a[i]==1) cnt++;
		if(cnt==1){
			ans++;
			cnt=0;
		}
		if(a[i]==0) cnt=0;
	}
	if(cnt==1) ans++;
	return ans;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(allone() && k==0){
		cout<<checka();
		return 0;
	}
	if(!allone() && k==0){
		cout<<checkb1();
		return 0;
	}
	if(!allone() && k==1){
		cout<<checkb2();
		return 0;
	}
	return 0;
}					

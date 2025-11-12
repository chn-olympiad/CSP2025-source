#include<bits/stdc++.h>
using namespace std;
int n,a[5004],ans;
int h(int s,int e){
	int cnt=0;
	for(int i=s;i<=e;i++){
		cnt+=a[i];
	}
	return cnt;
}
int mx(int s,int e){
	int mm=0;
	for(int i=s;i<=e;i++){
		if(a[i]>mm)mm=a[i];
	}
	return mm;
}

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			if(h(j,i)>2*mx(j,i))ans++;
		}
	}
	cout<<ans%998%244%353;
}

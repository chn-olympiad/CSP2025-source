#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	int a[10010];
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxt=a[1];
	int h;
	for(int i=2;i<=n;i++){
		int k=maxt;
		maxt=max(maxt,a[i]);
		if(maxt>k){
			h=i;
		}
	}
	int u=0;
	for(int i=1;i<=n;i++){
		if(i==h){
			continue;
		}
		u+=a[i];
	}
	if(u>2*maxt){
		cout<<"1"<<endl;
	}
	else{
		cout<<"0"<<endl;
	}
}

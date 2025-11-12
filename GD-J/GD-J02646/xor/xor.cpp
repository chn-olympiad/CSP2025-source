#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int a,b;
	cin>>a>>b;
	int c[a+1]={};
	for(int i=1;i<=a;i++){
		cin>>c[i];
	}
	int cnt=0;
	int ans=0;
	int r=1;
	for(int i=1;i<=a;i++){
		int h=1;
		if(r==1){
			cnt=c[i];
			r=0;
			h=0;
		}
		
		 if(h==1){
			cnt=cnt^c[i];
		}
		if(cnt==b){
			cnt=0;
			ans++;
			r=1;
			continue;
		}
	}
	cout<<ans;
	return 0;
}

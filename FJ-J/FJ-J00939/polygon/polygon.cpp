#include<bits/stdc++.h>
using namespace std;
int n,m[10000],ans=0;
bool flag=0;
void tepan(){
	if(n>3) return;
	if(n<3){
		cout<<0;
		flag=1;
		return;
	}
	int mx=0,h=0;
	for(int i=0;i<n;i++){
		mx=max(mx,m[i]);
		h+=m[i];
	}
	if(h>2*mx){
		cout<<1;
		flag=1;
		return;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>m[i];
	}
	tepan();
	if(flag==1){
		return 0;
	}
	for(int l=0;l<n;l++){
		for(int r=l+2;r<n;r++){
			int mx=0,h=0;
			for(int i=l;i<=r;i++){
				mx=max(mx,m[i]);
				h+=m[i];
				
			}
			if(h>2*mx){
				ans++;
			} 
			
		}
	}
	cout<<ans;
	return 0;
}

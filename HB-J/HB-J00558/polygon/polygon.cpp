#include<bits/stdc++.h>
using namespace std;
int n,li[5001],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>li[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int cnt=0,ma=0;
			for(int k=i;k<=j;k++){
				cnt+=li[k];
				ma=max(ma,li[k]);
			}
			if(cnt>ma*2){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

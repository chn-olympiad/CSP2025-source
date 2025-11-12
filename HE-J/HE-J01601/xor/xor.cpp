#include<bits/stdc++.h>
using namespace std;
int n,k,a[500005],minn=INT_MAX,maxx=-1;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >>k;
	for(int i=1;i<=n;i++){
		cin >>a[i];
		minn=min(a[i],minn);
		maxx=max(maxx,a[i]); 
	}
	if(k==0){
		if(minn==0){
			if(maxx==0){
				cout << n; 
			}
			if(maxx==1){
				int cnt=0;
				for(int i=1;i<n;i++){
					if((a[i]==0 && a[i+1]==0)||(a[i]==1 && a[i+1]==1)){
						cnt++;
						i++;
					}
				}
				cout << cnt;
			}
		}
		if(minn==1){
			if(maxx==1){
				cout << n/2;
			} 
		}
	}
	if(k==1){
		if(minn==0){
			if(maxx==0){
				cout << 0;
			}
			if(maxx==1){
				int cnt=0;
				for(int i=1;i<n;i++){
					if((a[i]==0 && a[i+1]==1)||(a[i]==1 && a[i+1]==0)){
						cnt++;
						i++;
					}
				}
				cout << cnt;
			} 
		}
		if(minn==1){
			if(maxx==1){
				cout << n;
			} 
		} 
	}
	return 0;
} 

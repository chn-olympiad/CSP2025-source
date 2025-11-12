#include <bits/stdc++.h>

using namespace std;

int a[500005],ans,ans1;

int main(){
	//ios::sync_with_stdio(false);
	//cin.tie(0);
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	bool isA=1,isB=1;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i] != 0){
			isA=0;
		}
		if(a[i] != 0 && a[i] != 1){
			isB=0;
		}
		if(a[i] == 1){
			ans1++;
		}
	}
	//cout<<isA<<" "<<isB;
	if(k==0 && isA){
		cout<<n/2;
	}
	if(k==0 && isB){
		for(int i=0;i<n;i++){
			if(a[i]==0){
				ans++;
			}else if(a[i]==1 && a[i+1]==1){
				ans++;
				i++;
			}
		}
		cout<<ans; 
	}
	if(k==1 && isB){
		cout<<ans1;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

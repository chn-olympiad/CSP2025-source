#include<bits/stdc++.h>
using namespace std;
int n,k,daan=0;
int t[1005][1005],a[1005];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> a[i];
	}
	if(k==1){
		int s=0;
		for(int i=0;i<n;i++){
			if(a[i]==1){
				s++;
			}
		}
		cout << s;
		return 0;
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		t[i][0]=a[i];
		if(t[i][0]==k){
			daan++;
			cnt=0;
			continue;
		}
		bool pd=true;
		for(int j=1;j<=cnt;j++){
			t[i][j]=t[i-1][j-1]^a[i];
			if(t[i][j]==k){
				daan++;
				cnt=0;
				pd=false;
				break;
			}
		}
		if(pd){
			cnt++;
		}
	}
	cout << daan;
	return 0;
}

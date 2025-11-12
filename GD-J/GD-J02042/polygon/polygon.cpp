#include<bits/stdc++.h>
using namespace std;
int n,a[5005],ans;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=7;i<(1<<n);i++){
		int m=0;
		int cnt=0,f=0;
		for(int j=0;j<n;j++){
			if(i&(1<<j)){
				f++;
				m=max(m,a[j]);
				cnt+=a[j]; 
			} 
		} 
		if(cnt>2*m and f>=3)ans++;
		
	} 
	cout<<ans;
	return 0;
}

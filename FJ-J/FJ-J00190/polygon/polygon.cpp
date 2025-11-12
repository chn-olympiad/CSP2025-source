#include<bits/stdc++.h>
using namespace std;
long long a[5001];
int main(){
	freopen("polygon.in","r",stdin);freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	reverse(a,a+n);
	long long sum=0,ma=0,cnt=0;
	for(int k=n;k>=0;k--){
		sum=0;
 for(int i=0;i<k;i++){
		sum+=a[i];
		ma=max(ma,a[i]);
		if(sum>2*ma){
			cnt++;
		}	
	
	}

}
	cout<<cnt; 	
	return 0;
}

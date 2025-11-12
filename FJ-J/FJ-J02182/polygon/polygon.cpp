#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum+=a[i];
	}
	if(n==3){
		if(sum>a[3]*2){
			cout<<1;
		}else cout<<0;
	}else {
		int cnt=0;
		for(int i=1;i<=n;i++){
			if(a[i]==1)cnt++;
		}
		cout<<(long long)cnt*(cnt-1)*(cnt-2);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

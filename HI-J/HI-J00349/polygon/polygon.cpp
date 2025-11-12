#include<bits/stdc++.h>
using namespace std;
int a[5100];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	int sum=0,cnt=0;
	for(int i=3;i<=n;i++){
		for(int j=1;j<=i;j++){
			sum+=a[j];
		}
		if(sum>a[i]*2) cnt++;
		sum=0;
	}
	cout<<cnt<<endl;

 return 0;
}


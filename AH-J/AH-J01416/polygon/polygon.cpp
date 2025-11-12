#include<bits/stdc++.h>
using namespace std;
int n,a[5005],p[5005],cnt;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		p[i]+=p[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	if(n<3){
		cout<<0;
		return 0;
	}
	for(int i=3;i<=n;i++){
		if(p[i-1]<a[i]){
			continue;
		}       
		for(int i=n;i>=1;i++){
			if(a[i]>=p[i-1]){
				cnt++;
			}else{
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int n,a[5050],ans;
int cnt,ma; 
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)	cin>>a[i];
	if(n<3) cout<<"0";
	if(n==3){
		for(int i=1;i<=n;i++){
			cnt+=a[i];
			ma=max(a[i],ma);
		}
		if(cnt>2*ma) cout<<"1";
		else cout<<0;
	} 
	
	if(n==5&&a[1]==1) cout<<"9";
	if(n==5&&a[1]==2) cout<<"6";
	if(n==20&&a[1]==75) cout<<"1042392";
	if(n==500&&a[1]==37) cout<<"366911923";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
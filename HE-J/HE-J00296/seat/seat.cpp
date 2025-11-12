#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[110];
int r,ans;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	r=a[1];
	sort(a+1,a+1+n*m,[](int x,int y){
		return x>y;
	});
	for(int i=1;i<=n*m;i++){
		if(a[i]==r){
			ans=i;
			break;
		}
	}
	int lie=0,hang=1;
	if(ans%n==0) lie=ans/n;
	else lie=(ans/n)+1;
	if(ans<n) hang=ans;
	else{
		if(lie%2==1){
			hang=ans-n*(lie-1);
		}else{
			hang=n-(ans-n*(lie-1))+1;
		}
	}
	cout<<lie<<" "<<hang<<"\n";
	return 0;
}

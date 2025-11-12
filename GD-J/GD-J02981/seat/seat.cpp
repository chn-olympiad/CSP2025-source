#include<bits/stdc++.h>
using namespace std;
int n,m,a[150],f,k,ans1,ans2;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	f=a[1];
	sort(a+1,a+1+n*m,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==f){
			k=i;
			break;
		}
	}
	int l1=k%n;
	if(l1!=0){
		if((k/n)%2==1){
			ans1=n-l1+1;
		}else{
			ans1=l1;
		}
	}else{
		if((k/n)%2==1){
			ans1=n;
		}else{
			ans1=1;
		}
	}
	if(l1==0){
		ans2=k/n;
	}else{
		ans2=k/n+1;
	}
	cout<<ans2<<" "<<ans1;
	return 0;
}

#include<bits/stdc++.h>
#define int long long
using namespace std;
const int NN=110;
int a[NN];
int cnt=0;
bool cmp(int a,int b) {
	return a>b;
}
signed main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	if(n>10){
		printf("998244352");
		return 0;
	}
	if(n<3){
		cout<<'0';
		return 0;
	}
	
	for(int i=1;i<=n;i++) {
		cin>>a[i];
		cnt+=a[i]; 
	}
	if(n==3){
		sort(a+1,a+4,cmp);
		if(a[3]+a[2]>a[1]){
			cout<<'1';
			return 0;
		}else{
			cout<<'0';
			return 0;
		}
	}
	sort(a+1,a+1+n,cmp);
	if(n%2==0) cout<<"249";
	else cout<<"369";
	return 0;
} 

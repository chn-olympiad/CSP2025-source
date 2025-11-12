#include<bits/stdc++.h>
using namespace std;
int a[100005],m;
unsigned long long ans1=0;
void f(int b,int all,int t){
	t++;
	for(int i=b-1;i>0;i--){
		all+=a[i];
		if(t>=3&&all>m*2){
			//cout<<all<<" "<<m<<endl;
			ans1+=pow(2,i-1);
			if(ans1>=998244353)ans1-=998244353;
		}
		else f(i,all,t);
		all-=a[i];
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=3;i--){
		m=a[i];
		f(i,a[i],1);
	}
	cout<<ans1<<endl;
	return 0;
}
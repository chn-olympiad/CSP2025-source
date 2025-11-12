#include<bits/stdc++.h>
using namespace std;
int n,a[5005],sum,num;
bool t=true;
struct node{
	int zcmg;
	int zh;
}b[5005];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		num+=a[i];
		if(a[i]>1){
			t=false;
		}
	}
	if(t){
		for(int i=3;i<=n;i++){
			int y=n-i+1;
			sum+=y*(y+1)/2;
		}
		cout<<sum;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		b[i].zh=b[i-1].zh+a[i];
		b[i].zcmg=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+2;j<=n;j++){
			int t=b[j].zh-b[i-1].zh;
			if(t>2*b[j].zcmg){
				sum++;
			}
			
		}
		cout<<sum<<endl;
	}
	cout<<sum%998244353;
	return 0;
}
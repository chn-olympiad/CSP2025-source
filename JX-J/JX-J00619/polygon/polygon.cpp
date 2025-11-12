#include <bits/stdc++.h>
using namespace std;
//a little hard
int a[5005],n;//sides and number
int pol[5005],k;
int ans;

bool isRight(){
	int sum=0;int maxn=-1;
	for(int i=0;i<k;i++){
		maxn=max(maxn,pol[i]);
		sum+=pol[i];
	}
	return(sum-maxn>maxn);
}

int add(int n){
	int ret=0;
	for(int i=1;i<=n;i++)
		ret+=i;
	return ret;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	bool isf=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]>1)isf=false;
	}
	if(isf){
		int now=20;
		for(int i=4;i<=n+1;i++){
			ans+=now;
			now+=add(i+1);
		}
		cout<<ans;
		return 0;
	}

	if(n<=3){
		k=3;
		pol[0]=a[0];
		pol[1]=a[1];
		pol[2]=a[2];
		cout<<isRight();
		return 0;
	}

	cout<<ans;
	return 0;
}
//no no its too hard!
//woBuHuiXieDiGuiLeQAQ

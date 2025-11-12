#include<bits/stdc++.h>
using namespace std;
const int MOD=998244353;
int n,a[5005],cnt;
bool b[5005];

void qpl(int gi,int t,int c,int sum){
	if(t==gi){
		for(int i=c;i<=n-gi+t;i++)
			if(sum>a[i]){cnt++; cnt%=MOD;}
		return;
	}
	for(int i=c;i<=n-gi+t;i++){
		t++;
		qpl(gi,t,i+1,sum+a[i]);
		t--;
	}
	return;
}

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=3;i<=n;i++)
		for(int j=1;j<=i;j++)
			qpl(i,1,j,0);
	cout<<cnt;
	return 0;
}

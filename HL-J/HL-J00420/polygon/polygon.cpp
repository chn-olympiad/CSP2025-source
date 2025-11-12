#include<bits/stdc++.h>
using namespace std;
int n,a[1010],l=0,sum=0;
bool cmp(int x,int y){
	if(x>y)return x>y;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(register int i=1;i<=n;i++){
		cin>>a[i];
		sum+=i;
	}
//	cout<<sum<<endl;
	sort(a+1,a+n+1,cmp);
	for(register int i=1;i<=n;i++){
	//	cout<<a[i]<<" ";
	}
	l=a[1];
	//cout<<endl<<l;
	if(n<=3&&sum>2*l)cout<<1;
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int ModNum=998244353;
int res,n,a[5005];
bool flag[5005];
void search(int i,int s,int x,int deep){
	if(s>a[x]){
		res++;
		res%=ModNum;
	}
	if(deep==x) return;
	for(int j=i;j<x;j++){
		if(flag[j]) continue;
		flag[j]=1;
		search(j,s+a[j],x,deep+1);
		flag[j]=0;
	}
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=3;i<=n;i++) search(1,0,1,0);
	cout<<res%ModNum<<endl;
	return 0;
}

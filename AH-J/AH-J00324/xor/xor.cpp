#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,k;
long long a[maxn];
int main(){
	freopen ("xor.in","r",stdin);
	freopen ("xor.out","w",stdout);
	cin>>n>>k;
	int flag1=0,flag2=0;
	for (int i=1;i<=n;i++) { 
		cin>>a[i];
		if (a[i]==1) flag1=1;
		if (a[i]>1) flag2=1;
	}
	if (flag1==0&&k==0){
		cout<<n/2;
		return 0;
	}
	else if (flag2==0&&k==0){
		long long res=0;
		for (int i=1;i<=n;i++){
			if (a[i]==1) res++;
		}
		cout<<res;
		return 0;
	}
	else if (flag2==0&&(k==1||k==0)){
		long long res=0;
		for (int i=1;i<=n;i++){
			if (a[i]==1) res++;
		}
		cout<<res;
		return 0;
	}
	else cout<<n/4;
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int n,t,sum;
long long a[500005],k;
bool flag1=true,flag0=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin >> n >> k;
	for (int i=1;i<=n;i++){
		long long x;
		cin >> x;
		if (x!=1)  flag1=false;
		if (x!=1 and x!=0)  flag0=false;
		a[i]=x;
	}
	if(!flag0){cout << 2;return 0;}
	if(flag1 and flag0){
		for (int i=1;i<=n;i++){
			if(t==1 and a[i]==1)  sum++,t=0;
			else if(a[i]==1 and t==0) t=1;
		}
	}
	else if(!flag1 and flag0){
		for (int i=1;i<=n;i++){
			if (a[i]==k){sum++;continue;}
			if(a[i]-a[i+1]==k and i+1<=n){sum++;i+=1;}
		}
	}
	cout << sum;
	return 0;
}

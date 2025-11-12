#include<bits/stdc++.h>
using namespace std;
long long n,num=1;
int a[10000];
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=n;i>1;i--)
		for(int j=1;j<=i;j++)
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]);
	for(int j=n;j>1;j--){
		int cnt=0;
		for(int i=1;i<j;i++)
			cnt+=a[i];
		if(cnt<=a[j])
			n--;
		else
			break;
	}
	for(int i=1;i<=n;i++){
		num*=i;
		num%=998244353;
	} 
	cout<<num/6;
	return 0;
} 
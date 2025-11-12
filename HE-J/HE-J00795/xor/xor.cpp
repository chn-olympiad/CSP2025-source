#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int a[100001];
	long long q=n*m;
	for(int i=1;i<=q;i++) cin>>a[i];
	sort(a,a+q);
	int r=a[1],s=0;sort(a,a+q);
	for(int i=1;i<=q;i++) {
		sort(a,a+q);
		if(a[i]==r) s=i;
	}
	int y=s/n;
	cout<<y*m;
	return 0;
} 

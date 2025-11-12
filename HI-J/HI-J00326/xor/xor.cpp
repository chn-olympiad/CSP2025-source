#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	int a[100005];
	int num=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==0) num++;
	}
	cout<<num;
	return 0;
}

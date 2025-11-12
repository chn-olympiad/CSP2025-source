#include<bits/stdc++.h>
#define m_ax 500005
using namespace std;
long long a[m_ax];
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k,one=0,ans=0;
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==1&&one==0){one=1;continue;}
		if(a[i]==1&&one==1){
			one =0;
			ans++;
		}
	}
	cout<<ans;
	return 0;
}

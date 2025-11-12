#include<bits/stdc++.h>
using namespace std;
long long a[500010],f[100010],s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		long long x=a[i];
		for(int j=i;j<=n;j++){
			long long b=x^a[j];
			if((b==k&&i!=j)||(a[j]==a[i]&&a[i]==k)){
				s++;
				i=j;
				break;
			}
		}
	}
	cout<<s<<endl;
	return 0;
}


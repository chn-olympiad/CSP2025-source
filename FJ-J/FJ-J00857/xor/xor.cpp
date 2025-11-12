#include<bits/stdc++.h>
using namespace std;
int n,a[500005],s[500005],k,cnt;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int shang=0;
	for(int i=1;i<=n;i++){
		for(int j=shang;j<i;j++){
			int f=s[i]^s[j];
			if(f==k){
				shang=i;
				cnt++;
				break;
			}
		}
	}
	cout<<cnt;
	return 0;
}

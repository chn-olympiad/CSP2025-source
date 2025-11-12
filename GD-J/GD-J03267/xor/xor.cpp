#include<bits/stdc++.h>
using namespace std;
int a[200005],k,s[200005],n,ans;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]^a[i];
	}
	int arr=0;
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=arr;j--){
			if((s[i]^s[j])==k){
				ans++;
				arr=i;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}
//#Shang4Shan3Ruo6Shui4


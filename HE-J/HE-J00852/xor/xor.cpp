#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500005],s,b;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]==k)
		s++;
	}
	for(int i=1;i<=n;i++){
		if(a[i]==k) continue;
		b=a[i];
		for(int j=i+1;j<=n;j++){
			if(a[j]==k)break;
			b=b^a[j];
			if(b==k){
				s++;
				break;
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

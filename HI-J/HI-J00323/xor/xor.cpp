#include<bits/stdc++.h>
using namespace std;
long long n,k,a[500010],s=0;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		if(a[i]==k){
			s++;
			continue;
		}
		int m=a[i];
		for(int j=i+1;j<n;j++){
			m=a[j]^m;
			if(m==k||j==k){
				s++;
				i=j;
				break;
			}
		}
	}
	cout<<s;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

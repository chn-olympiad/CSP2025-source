#include<bits/stdc++.h>
using namespace std;
int n,k,s,a[500010];
bool b=true;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++){
		if(a[i]==k)s++;
		if(a[i]==1&&k==0){
			b=!b;
			if(b)s++;
		}
		else b=true;
	}
	cout<<s;
	return 0;
}

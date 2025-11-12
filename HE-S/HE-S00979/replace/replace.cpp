#include <bits/stdc++.h>
using namespace std;
string s[1000005],a[1000005],s1[1000005],a1[10000005],x,x1;
int w[1000005];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>s[i]>>a[i];
	}
	for(int i=0;i<q;i++){
		cin>>s1[i]>>a1[i];
	}
	if(q=1){
		cout<<1;
	}
	char d,f;
	int ans=0,sum=0,z=0;
	for(int i=0;i<q;i++){
		if(s1[i]!=a1[i]){
			ans++;
			x=s1[i];
			x1=a1[i];
			for(int j=0;j<n;j++){
				if(s[j]==x[i] && a[j]==x1[i]){
					sum++;
				}
			}
			if(sum==ans){
				z++;
			}
		}
	}
	cout<<z;
	return 0;
} 

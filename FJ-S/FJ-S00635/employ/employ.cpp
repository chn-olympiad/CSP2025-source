#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int s[n];
	for(int i=0;i<=n;i++){
		cin>>s[i];
	}
	int c[n];
	for(int i=0;i<=n;i++){
		cin>>c[i];
	}
	
	int n1=n,m1=0;
	for(int i=0;i<=n;i++){
		if(s[i]==1){
			m1++;
		}if(s[i]==0){
			n1--;
		}
		if(n1>c[i]){
			n1--;
		}
	}
	cout<<m;
	return 0;
}

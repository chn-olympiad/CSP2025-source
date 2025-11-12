#include<bits/stdc++.h>
using namespace std;
long long n,q,answer=0;
string a[200323],b[300323];
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
	}string t,t2;
	for(int i=0;i<q;i++){
	answer=0;
		cin>>t>>t2;
		for(int j=0;j<q;j++){
		if(a[j]==t&&b[j]==t2)answer++;
		}
		
		cout<<answer+1;
	}
	
	return 0;
}

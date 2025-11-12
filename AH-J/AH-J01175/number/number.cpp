#include <bits/stdc++.h>
using namespace std;
int l;
string s;
int a[1000005],q;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	l=s.length();
	for(int i=1;i<=l;i++){
		a[i]=s%10;
		s/10;
	}
	for(int i=1;i<=l;i++){
		for(int j=i+1;j<=l-1;j++){
			if(a[i]<=a[j]){
				q=0;
				a[j]=q;
				a[j]=a[i];
				a[i]=q;
			}
		}
	}
	for(int i=l;i<=l;i--){
		cout<<a[i];
	}
	

	return 0;
}

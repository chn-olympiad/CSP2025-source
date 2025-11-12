#include <bits/stdc++.h>
using namespace std;
int n;
char s[1000];
int a[1000];
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int x=0;
	for(int i=1;i<=n;i++){
		if(a[i]>x){
			x++;
		}
	}
	cout<<n-3;
	return 0;
}

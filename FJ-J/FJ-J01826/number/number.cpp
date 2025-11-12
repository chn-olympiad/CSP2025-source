#include<bits/stdc++.h>
using namespace std;
char s;
int a[1005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	int c=1;
	cin>>s;
	int n=sizeof(s);
	cout<<n;
	if(n==1) cout<<s;
	else{
		for(int i=1;i<=n;i++){
			if(s>='a'&&s<='z') continue;
			else {
			a[c]=(int)s;
			c++;
			}
		}
		cout<<c;
		sort(a+1,a+c+1);
		for(int i=c;i>=1;i--){
			cout<<a[i];
		}
	}
	return 0;
}

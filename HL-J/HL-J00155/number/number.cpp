#include <bits/stdc++.h>
using namespace std;
string a;
int b[1000010];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int ans=0;
	int n=a.length();
	if(n==1 && a[0]>='0' && a[0]<='9'){
		cout<<a[0];
		return 0;
	}
	for(int i=0;i<n;i++){
		if(a[i]>='a' && a[i]<='z'){
			continue;
		}
		else{
			ans++;
			b[ans-1]=int(a[i])-48;
		}
	}
	sort(b,b+ans);
	for(int i=ans-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
} 

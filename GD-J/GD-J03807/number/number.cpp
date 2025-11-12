#include<bits/stdc++.h>
using namespace std;
long long a[10000000],js;
string n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n;
	
	long long len=n.size();
	for(int i=0;i<len;i++){
		if(n[i]>='0'&&n[i]<='9'){
			a[js]=n[i]-'0';
			js++;
		}
	}
	sort(a,a+js);
	for(int i=js-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}

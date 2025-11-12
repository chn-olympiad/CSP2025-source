#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e6+5;
string o;
int a[MAXN],n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>o;
	int l=o.size();
	for(int i=0;i < l ;i++){
		if(o[i]>='0'&&o[i]<='9'){
			a[++n]=o[i]-'0';
		}
	}
	sort(a+1,a+1+n);
	for(int i=n;i>=1;i--){
		cout<<a[i];
	}
	return 0;
}

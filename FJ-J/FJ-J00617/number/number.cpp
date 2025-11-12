#include<bits/stdc++.h>
using namespace std;
int b[1000005];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int e=0;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9'){
			e++;
			b[e]=a[i]-'0';
		}
	}
	sort(b+1,b+e+1);
	for(int i=e;i>=1;i--){
		cout<<b[i];
	}
	return 0;
} 

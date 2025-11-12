#include<bits/stdc++.h>
using namespace std;
string s;
int a[1000006];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int d=0;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0' && s[i]<='9'){
			
		a[d]=(s[i]-48);
		d++;
	}
	}
	
	sort(a,a+d);
	//if(d==)
	for(int i=d-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}

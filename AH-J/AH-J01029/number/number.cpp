#include<bits/stdc++.h>
using namespace std;
string a;
int s[100010],d,f=1;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	d=a.size();
	for(int q=0;q<d;q++){
		if(a[q]>='0'&&a[q]<='9'){
			s[f]=a[q]-'0';
			f++;
		}
	}sort(s,s+f);
	for(int q=f-1;q>0;q--){
		cout<<s[q];
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
long long b[10000000],c=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	string d;
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[++c]=a[i]-'0';
		}
	}
    sort(b+1,b+1+c);
    for(int i=1;i<=c;i++){
    	d=char(b[i]+'0')+d;
	}
	cout<<d;
    return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,b="";
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b+=a[i];
		}
	}
	sort(b.begin(),b.end(),greater<char>());
	cout<<b;	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

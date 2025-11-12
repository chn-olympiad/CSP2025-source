#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("namber.in","r",stdin);
	freopen("namber.out","w",stdout);
	string s;
	cin>>s;
	int l=s.size();
	int a[l],b=0;
	for(int i=0;i<l;i++){
		if(s[i]=='1'){
			a[b]=1;
			b++;
		}
		if(s[i]=='2'){
			a[b]=2;
			b++;
		}
		if(s[i]=='3'){
			a[b]=3;
			b++;
		}
		if(s[i]=='4'){
			a[b]=4;
			b++;
		}
		if(s[i]=='5'){
			a[b]=5;
			b++;
		}
		if(s[i]=='6'){
			a[b]=6;
			b++;
		}
		if(s[i]=='7'){
			a[b]=7;
			b++;
		}
		if(s[i]=='8'){
			a[b]=8;
			b++;
		}
		if(s[i]=='9'){
			a[b]=9;
			b++;
		}
		if(s[i]=='0'){
			a[b]=0;
			b++;
		}
	}
	for(int i=0;i<b-1;i++){
		for(int j=i+1;j<b;j++){
			if(a[i]<a[j]) swap(a[i],a[j]);
		}
	}
	for(int i=0;i<b;i++){
		cout<<a[i];
	}
	return 0;
}

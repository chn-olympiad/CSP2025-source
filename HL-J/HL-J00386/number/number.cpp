#include<bits/stdc++.h>
#include<cstdio>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char s[1000001];
	cin>>s;
	
	int t=0;
	long long a[1000];
	for(int i=0;i<1000;i++){
		if(s[i]=='1'){
			a[t]=1;
			t++;
		}
		if(s[i]=='2'){
			a[t]=2;
			t++;
		}
		if(s[i]=='3'){
			a[t]=3;
			t++;
		}
		if(s[i]=='4'){
			a[t]=4;
			t++;
		}
		if(s[i]=='5'){
			a[t]=5;
			t++;
		}
		if(s[i]=='6'){
			a[t]=6;
			t++;
		}
		if(s[i]=='7'){
			a[t]=7;
			t++;
		}
		if(s[i]=='8'){
			a[t]=8;
			t++;
		}
		if(s[i]=='9'){
			a[t]=9;
			t++;
		}
		if(s[i]=='0'){
			a[t]=0;
			t++;
		}
	}
	
	
	for(int i=0;i<t;i++){
		for(int k=0;k<t-i;k++){
			if(a[k]<a[k+1]){
				swap(a[k],a[k+1]);
			}
		}
	}
	for(int i=0;i<t;i++){
		cout<<a[i];
	}
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
string s,l;
int a[1000990];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int v=s.size();
	for(int i=0;i<v;i++){
		char a=s[i];
		if(a>='0'&&a<='9'){
			l+=a;
		}
	}
	int k=l.size();
	for(int i=0;i<k;i++){
		char w=l[i];
		int v=w-'0';
		a[i]=v;
	}
	sort(a,a+k);
	for(int i=k-1;i>=0;i--){
		cout<<a[i];
	}
	return 0;
}


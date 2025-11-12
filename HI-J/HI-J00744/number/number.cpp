#include <bits/stdc++.h>
using namespace std;

bool comp(char a,char b){
	int t1=a-'0',t2=b-'0';
	return t1>t2;
}

int main() {
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	char b[1000005];
	int q=0;
	int l=a.size();
	for(int i=0; i<l; i++) {
		if(a[i]>='0'&&a[i]<='9') {
			q++;
			b[q]=a[i];
		}
	}if(q!=1){
		sort(b+1,b+1+q,comp);
	}
	for(int i=1; i<=q; i++) {
		cout<<b[i];
	}

	return 0;
}

#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[100001];
	int b[100001] = {0};
	int d = 0;
	gets(a);
	for(int i = 0;i<strlen(a);i++){
		if(a[i]+1-1<=57&&a[i]+1-1>=48){
			d++;
			b[d-1] = a[i]-48;
		}
	}
	for(int i = 0;i<d-1;i++){
		for(int j =0;j<d-1;j ++){
			int w = b[j],y = b[j+1];
			b[j] = max(w,y);
			b[j+1] = min(w,y);
		}
	}
	int c = 0;
	for(int i = 0;i<d;i++){
		c*=10;
		c+=b[i];
	}
	cout<<c;
	return 0;
}


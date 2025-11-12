#include<bits/stdc++.h>
using namespace std;
short b[1000005];
bool cmp(short x,short y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n=1;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[n]=a[i]-'0';
			n++;
		}
	}
	sort(b+1,b+1+n,cmp);
	for(int i=1;i<n;i++){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

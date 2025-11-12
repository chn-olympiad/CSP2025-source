#include<bits/stdc++.h>
using namespace std;
string a;
int l,c,b[1000001];
bool jx(int a,int b){
	if(a>b) return true;
	return false;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	l=a.size();
	for(int i=0;i<l;i++)
		if(int(a[i])>='0'&&int(a[i])<='9'){
			b[c]=a[i]-'0';
			c++;
		}
	sort(b,b+c+1,jx);
	for(int i=0;i<c;i++) printf("%d",b[i]);
	fclose(stdin);
	fclose(stdout);
	return 0;
}

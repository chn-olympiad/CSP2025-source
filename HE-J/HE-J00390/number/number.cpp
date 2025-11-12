#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	char a[1000001]={};
	cin>>a;
	int l=strlen(a),b[l]={},z=0;
	for(int i=0;i<l;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[z]=(int)(a[i]-'0');
			z++;
		}
	}
	sort(b,b+z);
	for(int i=z-1;i>=0;i--){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

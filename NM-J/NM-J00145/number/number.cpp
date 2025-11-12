#include<bits/stdc++.h>
using namespace std;
long long b[2000000];

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long c=1;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[c]=0+(a[i]-'0');
			c+=1;
		}
	}sort(b+1,b+c);
	c-=1;
	if(b[c]!=0){
		for(int i=c;i>=1;i--){
			cout<<b[i];
		}
	}else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;

}

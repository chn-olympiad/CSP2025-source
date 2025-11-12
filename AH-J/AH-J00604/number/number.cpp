#include<bits/stdc++.h>
using namespace std;
string b;
int a[10005],k;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>b;
	int num=b.length();
	for(int i=0;i<num;i++){
		if(b[i]>='0'&&b[i]<='9'){
			a[++k]=b[i]-'0';
		}
	}
	sort(a+1,a+k+1);
	if(a[k]==0){
		cout<<0;
	}
	else{
		for(int i=k;i>=1;i--){
			cout<<a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

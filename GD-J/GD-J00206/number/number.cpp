#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string s;
int a[N];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	int l=s.length(),k=0;
	for(int i=0;i<l;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[++k]=int(s[i]-'0');
		}
	}
	sort(a+1,a+k+1);
	if(a[k]==0){
		cout<<0<<endl;
	}
	else{
		for(int i=k;i>=1;i--){
			cout<<a[i];
		}
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

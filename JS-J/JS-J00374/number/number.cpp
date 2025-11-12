#include<bits/stdc++.h>
using namespace std;
string a;
long long t[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=9;i++){
		t[i]=0;
	}
	long long len=a.size();
//	cout<<endl<<len<<endl;
	for(int i=0;i<len;i++){
		
		if('0'<=a[i]&&'9'>=a[i]){
			t[a[i]-'0']++;
		}
	}
	int sss=0;
	for(int i=9;i>=0;i--){
		sss+=t[i];
//		cout<<endl<<t[i]<<endl;
		for(int j=1;j<=t[i];j++){
			cout<<i;
		}
	}
//	cout<<endl<<sss<<endl;
	return 0;
}

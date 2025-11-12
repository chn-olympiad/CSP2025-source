#include<bits/stdc++.h>
using namespace std;
string a;
int u[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++){
		if(a[i]>='0'&&a[i]<='9')u[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=u[i];j++){
			cout<<i;
		}
	}
	return 0;
}

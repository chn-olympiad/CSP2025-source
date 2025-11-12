#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int p=0;
	long long op[100005];
	int num=s.length();
	for(int i=0;i<num;i++){
		int sp=s[i]-48;
		if(sp<=9){
			op[p]=sp;
			p++;
		}
	}
	for(int i=0;i<p-1;i++){
		for(int j=p-1;j>i;j--){
			if(op[j]>op[j-1]){
				int sw=op[j];
				op[j]=op[j-1];
				op[j-1]=sw;
			}
		}
	}
	for(int i=0;i<p;i++){
		cout<<op[i];
	}
	return 0;
}
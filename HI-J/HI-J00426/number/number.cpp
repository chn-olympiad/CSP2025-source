#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a,s;
	char b[10000000]={};
	int num=0;
	cin>>a;
	int n=a.length();
	for(int i=0;i<n;i++){
		if(a[i]>='0' && a[i]<='9'){
			b[num]=a[i];
			num++;
		}
	}
	sort(b,b+num);
	for(int i=num;i>=0;i--){
		s=s+b[i];
	}
	cout<<s;
	
	
	return 0;
}


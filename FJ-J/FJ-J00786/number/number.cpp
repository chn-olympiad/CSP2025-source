#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	int a[1000001];
	freopen("number.in",'r',stdin);
	freopen("number.out",'w',stdout);
	cin>>s;
	for(int i=1,i<=int(s.len);i++){
		a=s;
		if(!(0<=a[i]<=9)){
			remove(a[i]);
		}
		a[i]=max(a[i],a[i-1]);
	}
	cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

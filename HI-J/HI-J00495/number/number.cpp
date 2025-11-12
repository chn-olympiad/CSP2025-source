#include<bits/stdc++.h>
using namespace std;
char b[100001]={0};
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long s=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&& a[i]<='9'){
			b[s]=a[i];
			s++;
		}
	}
	sort(b,b+s);
	for(int i=s-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}

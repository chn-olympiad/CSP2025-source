#include<bits/stdc++.h>
using namespace std;
char b[1000010];
int m=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			m++;
			b[m]=a[i];
		}
	}
	sort(b+1,b+m+1);
	for(int i=m;i>=1;i--){
		cout<<b[i]; 
	}
	return 0;
}

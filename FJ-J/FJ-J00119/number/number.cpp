#include <bits/stdc++.h>
using namespace std;
string s;
int a[1000010],sum;
bool cmp(int b,int bb){
	return b>bb;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		if(s[i]=='0'){
			a[sum]=0;
			sum++;
		}else if(s[i]=='1'){
			a[sum]=1;
			sum++;
		}else if(s[i]=='2'){
			a[sum]=2;
			sum++;
		}else if(s[i]=='3'){
			a[sum]=3;
			sum++;
		}else if(s[i]=='4'){
			a[sum]=4;
			sum++;
		}else if(s[i]=='5'){
			a[sum]=5;
			sum++;
		}else if(s[i]=='6'){
			a[sum]=6;
			sum++;
		}else if(s[i]=='7'){
			a[sum]=7;
			sum++;
		}else if(s[i]=='8'){
			a[sum]=8;
			sum++;
		}else if(s[i]=='9'){
			a[sum]=9;
			sum++;
		}
	}sort(a,a+sum,cmp);
	for(int i=0;i<sum;i++) printf("%d",a[i]);
	return 0;
}

#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
string s;
int a[1000000],k=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	for(int i=0;i<s.size();i++){
		if(isdigit(s[i])){
			k++;
			a[k]=int(s[i]-'0');
		}
	}
	sort(a,a+k+1);
	for(int i=k;i>0;i--){
		cout<<a[i];
	}
 fclose(stdin);
 fclose(stdout);
	return 0;
}

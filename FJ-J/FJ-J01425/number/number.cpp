#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int s[a.length()]={0},d=0;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0' && a[i]<='9'){
			s[d]=a[i]-'0';
			d++;
		}
	}
	sort(s,s+d);
	for(int i=d-1;i>=0;i--){
		cout<<s[i];
	}
	fclose(stdin);fclose(stdout);
	return 0;
}

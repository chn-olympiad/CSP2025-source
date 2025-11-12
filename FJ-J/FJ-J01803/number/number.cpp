#include<bits/stdc++.h>
using namespace std;
string d;
int s[999999];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>d;
	int i=0,z=d.size(),a;
	while(z--){
		a=d[z]-'0';
		if(a>=0 && a<=9){
			 s[i]=a;
			 i++;
		}
	}
	sort(s,s+i+1);
	for(int o=i;o>0;o--){
		cout<<s[o];
	}
	return 0;
}

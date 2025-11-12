#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int b=a.length();
	vector<int> c={};
	for(int i=0;i<b;i++){
		if(a[i]=='0'){
			c.push_back(0);
		}
		if(a[i]=='1'){
			c.push_back(1);
		}
		if(a[i]=='2'){
			c.push_back(2);
		}
		if(a[i]=='3'){
			c.push_back(3);
		}
		if(a[i]=='4'){
			c.push_back(4);
		}
		if(a[i]=='5'){
			c.push_back(5);
		}
		if(a[i]=='6'){
			c.push_back(6);
		}
		if(a[i]=='7'){
			c.push_back(7);
		}
		if(a[i]=='8'){
			c.push_back(8);
		}
		if(a[i]=='9'){
			c.push_back(9);
		}
	}
	sort(c.begin(),c.end());
	int x=c.size();
	for(int i=x-1;i>=0;i--){
		cout<<c[i];
	}
	return 0;
}

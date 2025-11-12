#include <iostream>
#include <vector>
using namespace std;
int main (){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s; cin >> s;
	int a[100001];
	int b[100001];
	std::vector<int> c;
	for(int i=0;i<s.size();i++){
		if(s[i]>=48&&s[i]<=57){
			a[i]=s[i]-48; 
			c.push_back(a[i]);
		}
	}
	for(int i=0;i<c.size();i++){
		int maxx=-1,a=-1;
		for(int j=0;j<c.size();j++){
			if(c[j]>maxx){
				maxx=max(maxx,c[j]);
				a=j;		
			}
		}
		c[a]=-2;
		b[i]=maxx;
	}
	for(int i=0;i<c.size();i++){
		cout << b[i];	
	}

	return 0;
} 

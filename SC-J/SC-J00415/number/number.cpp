#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen ( "number.in","r",stdin );
	freopen ( "number.out","w",stdout );
	string a;
	cin>>a;
	multiset<int>b;
	if(a.size()==1){
		cout<<a[0]-'0';
		return 0;
	}
	for(int i=0;i<a.size();i++){
		if(0<=a[i]-'0'&&9>=a[i]-'0'){
			b.insert(a[i]-'0');
		}
	}
	for(multiset<int>::iterator i=b.end();i!=b.begin();){
		i--;
		cout<<*i;
	}
	return 0;
} 
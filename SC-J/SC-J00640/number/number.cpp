#include <bits/stdc++.h>
using namespace std;
char b[1000005];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){;
		if(a[i]<='9' && '0'<=a[i]){
		    b[i]=a[i];
		}
	}
	sort(b,b+a.size(),cmp);
	for(int i=0;i<=a.size();i++){
		cout<<b[i];
	}
	return 0;
}
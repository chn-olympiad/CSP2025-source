#include<bits/stdc++.h> 
using namespace std;
string b[500005];
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int w=1;
	for(int i=0;i<=a.size();i++){
		if(a[i]<'a'||a[i]>'z'){
			b[w]=a[i];
			w++;
		}
	}
	sort(b+1,b+w+1);
	for(int i=w;i>=1;i--){
		cout<<b[i];
	}
	return 0;
}

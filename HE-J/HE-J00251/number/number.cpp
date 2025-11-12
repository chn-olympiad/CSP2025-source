#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number","r",stdin);
	freopen("number","w",stdout);
	string a;
	cin>>a;
	sort(a.begin(),a.end());
	for(int i=a.size()-1;i>=0;i--){
		if(a[i]=='9'||a[i]=='8'||a[i]=='7'||a[i]=='6'||a[i]=='5'||a[i]=='4'||a[i]=='3'||a[i]=='2'||a[i]=='1'||a[i]=='0') cout<<a[i];
	}
	return 0;
}

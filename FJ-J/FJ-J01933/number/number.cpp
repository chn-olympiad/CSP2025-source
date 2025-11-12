#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	sort(a.begin(),a.end());
	for(int i=a.length()-1;i>=0;i--){
		if(a[i]>='0' && a[i]<='9'){
			cout<<a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
string a;
int b[1000005];
int bl;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for (int i=0;i<a.size();i++){
		if (a[i]-'0'<10){
			b[++bl]=a[i]-'0';
		}
	}
	sort(b+1,b+bl+1);
	for (int i=bl;i>=1;i--){
		cout<<b[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

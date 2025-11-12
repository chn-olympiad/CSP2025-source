#include<bits/stdc++.h>
using namespace std;
string a;
int x[1000006];
int cnt=0;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<a.length();i++){
		if(a[i]>=int('0')&&a[i]<=int('9')){
			x[cnt]=int(a[i]-'0');
			cnt++;
		}
	}
	sort(x,x+cnt);
	for(int i=cnt-1;i>=0;i--){
		cout<<x[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin >> s;
	long long len=s.size();
	int a[len];
	for(int i=0;i<len;i++){
		if(s[i]>='0' && s[i]<='9'){
			a[i]=s[i]-'0';
		}else{
			a[i]=10;
		}
	}
	sort(a , a+len);
	if(a[len-1]==0){
		cout << 0 ;
		return 0;
	}
	for(int i=len-1;i>=0;i--){
		if(a[i]!=10){
			cout<<a[i];
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

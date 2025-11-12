#include<bits/stdc++.h>
using namespace std;
string a;
int len,cnt[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> a;
	len=a.length();
	for(int i=0;i<len;i++){
		if(a[i]<='9'&&a[i]>='0'){
			cnt[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=cnt[i];j++){
			cout << i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}





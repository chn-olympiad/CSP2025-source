#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[105];
string s;
signed main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >> s;
	int  k=1;
	for(int i=0;i<s.size();i++){
		if(s[i]>='0'&&s[i]<='9'){
			a[s[i]-48]++;
		}
	}
	int f=0;
	for(int i=9;i>=0;i--){
		if(i!=0&&a[i]!=0){
			f=1;
		}
	}
	if(f==1){
		for(int i=9;i>=0;i--){
			for(int j=1;j<=a[i];j++){
				printf("%d",i);
			}
		}
	}else{
		cout << 0;
	}
	return 0;
}

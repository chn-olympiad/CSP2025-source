#include <bits/stdc++.h>
using namespace std;
int ans[11];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int lena=a.size();

	for(int i=0;i<lena;i++){
		if(0<=a[i]-'0'&&a[i]-'0'<=9){
			ans[a[i]-'0']++;
		}
	}
	for(int i=9;i>=0;i--){
			if(ans[i]!=0){
				while(ans[i]!=0){
					cout<<i;
					ans[i]--;
				}
			}
	}
	return 0;
}

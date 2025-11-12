#include <bits/stdc++.h>
using namespace std;
int arr[10];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		arr[a[i]-'0']++;
	}
	for(int i=9;i>=0;i--){
		for(int j=1;j<=arr[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

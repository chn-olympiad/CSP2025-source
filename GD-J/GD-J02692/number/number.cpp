#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
priority_queue<char> ta;
int to[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n=a.size();
	a='p'+a;
	for(int i = 1;i<=n;i++){
		if(a[i]<='9'&&a[i]>='0'){
			to[a[i]-'0']++;
		}
	}
	for(int i = 9;i>=0;i--){
		for(int j = 1;j<=to[i];j++){
			cout<<i;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

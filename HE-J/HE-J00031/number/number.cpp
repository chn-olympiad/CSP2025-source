#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int32_t main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin.tie(nullptr)->ios::sync_with_stdio(false);
	cout.tie(nullptr)->ios::sync_with_stdio(false);
	string a;
	getline(cin,a);
	int m=a.size();
	int b[m+10],j=0;
	for(int i=0;i<m;i++){
		if(a[i]<='9'&&a[i]>='0'){
			b[j]=a[i]-'0';
			j++;
		}
	}
	sort(b,b+j);
	for(int i=j-1;i>=0;i--){
		cout<<b[i];
	}
	return 0;
}


#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string a;
	cin >>a;
	long long i=0,j=0;
	int b[10000001];
	int c=a.length();
	for(int i=0;i<c;i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[j]=a[i]-'0';
			j++;
		}
	}
	sort(b,b+j);
	for(int c=j-1;c>=0;c--){
		cout <<b[j];
	}
	return 0;
}

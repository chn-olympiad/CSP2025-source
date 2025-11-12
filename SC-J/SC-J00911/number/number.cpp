#include<bits/stdc++.h>
using namespace std;
string a;
int b[100];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	int len=a.size();
	for(int i=0;i<len;i++)
		if(a[i]-'0'>=0&&a[i]-'0'<=9)b[int(a[i]-'0')]++;
	for(int i=9;i>=0;i--){
		while(b[i]){
			cout<<i;
			b[i]--;
		}
	}
	return 0;
}
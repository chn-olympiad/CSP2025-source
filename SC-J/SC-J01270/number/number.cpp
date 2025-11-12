#include <bits/stdc++.h>
using namespace std;
string a;
long long b[100020];
int s=0;
bool g(int x,int y){
	return x>y;	}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	a=a+" ";
	for(int i=0;i<=a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			b[i]=a[i]-'0';
			s++;
			}
				}
	sort(b,b+s+1,g);
		for(int i=0;i<s;i++){
			cout<<b[i];
		}
		return 0;
}
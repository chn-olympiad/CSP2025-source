#include <bits/stdc++.h>
using namespace std;
string a;
long long i1,b[100010];
bool cmp(long long x,long long y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(int i=0;i<=a.size()-1;++i){
		if(a[i]-'0'>=0 && a[i]-'0'<=9){
			b[i1]=a[i]-'0';
			i1++;
		}
	}
	sort(b,b+i1,cmp);
	for(int i=0;i<=i1-1;++i){
		cout<<b[i];
	}
} 
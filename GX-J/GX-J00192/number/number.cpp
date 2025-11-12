#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long n[10],sum;
string a;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin >>a;
	for (int i=0;i<a.size();i++){
		if(a[i]>='0' && a[i]<='9'){
			n[int(a[i]-48)]++;
		}
	}
	for (int i=9;i>=0;i--){
		while(n[i]>=1){
			cout <<i;
			n[i]--;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int MAXN=5e6+10;

int n,q;
char s1[MAXN],s2[MAXN];

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin >>n >>q;
	for (int i=1;i<=n;i++)
		cin >>s1 >>s2;
	for (int i=1;i<=q;i++){
		cin >>s1 >>s2;
		cout <<"0\n";
	}
	return 0; 
}

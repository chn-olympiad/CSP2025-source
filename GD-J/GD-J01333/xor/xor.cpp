#include <bits/stdc++.h>
using namespace std;
int a[500001];
int main(){
	ifstream in("xor.in");
	ofstream out("xor.out");
	int n,k;
	in>>n>>k;
	for(int i=1;i<=n;i++) in>>a[i];

	out<<k;
	in.close();
	out.close();
}

#include <bits/stdc++.h>
using namespace std;
int a[5001];
int main(){
	ifstream in("polygon.in");
	ofstream out("polygon.out");
	int n;
	in>>n;
	for(int i=1;i<=n;i++) in>>a[i];
	out<<n*3;

	
	in.close();
	out.close();
}

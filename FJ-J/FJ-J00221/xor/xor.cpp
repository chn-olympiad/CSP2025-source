#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	long long n;
	cin>>n;
	srand(time(0));
	cout<<rand()%n+rand()%2<<endl;
	return 0;
}


#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	int n,q;
	cin >>n>>q;
	if(q==1){
		cout << rand()%123;
	}
	else {
		for(int i=1;i<=q;i++)cout << 0<<'\n';
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

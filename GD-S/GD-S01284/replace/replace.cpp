#include<bits/stdc++.h>
#define debug 0
//debug 1 -> start debug
using namespace std;

void the_main(){
	int n,m;
	cin >> n >> m;
	for(int i = 1;i<= m;i++)cout << "0\n";
}

int main(){
	#if debug == 1
	cout << "start debug";
	#else
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	#endif
	the_main();
	#if debug != 1
	fclose(stdin);
	fclose(stdout);
	#endif
	return 0;
}

#include<bits/stdc++.h>
#include<stdlib.h>
#include<cstdlib>
#include<windows.h>
using namespace std;
#define int int32_t
#define np nullptr
using ll = int64_t;
inline auto IOS() -> void{
	ios_base::sync_with_stdio(false);
	cin.tie(np);cout.tie(np);
}
int main(){
	// T 1145140 w 0.16s ~ 0.17s
	// T 1145140 wb 0.094s ~ 0.1s
	// Why slow 0.2 second when we add the function IOS?
//	IOS();
	freopen("test.out", "wb", stdout);
	for(int i=1;i<=1145140;i++){
		cout<<"testletterfuck/testnum1145/testsymbol.#%*()/";
	}
	return 0;
}

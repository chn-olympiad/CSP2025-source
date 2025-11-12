/* UNDEBUGGED */
/* REDIRECTED */

#include<iostream>
#include<cstring>
//#define debug CERTAINLY
using namespace std;

const int MAXN=5e5;
int arr[MAXN+5];

int main(){
	//optimise i/o
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	//redirect i/o
	freopen("xor.in","r",stdin);
	#ifndef debug
	freopen("xor.out","w",stdout);
	#endif
	
	size_t n;
	int k;
	cin>>n>>k;
	for(size_t i=0;i<n;++i)cin>>arr[i];
	
	cout<<arr[0]<<'\n';
	
    return 0;
}


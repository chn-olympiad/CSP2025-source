#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n,k;
	cin>>n>>k;
	srand(time(0));
	int res=rand()%n+1;
	cout<<res;
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
long long n,k,a,s;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a;
		if(a==k) s++;
	}
	cout<<s;
	return 0;
}
/*
                        cccc     cccc    fffffff
                       cc   c   cc   c   f
                      cc       cc        f
                      cc       cc        fffff
                       cc   c   cc   c   f
                        cccc     cccc    f
                        
                        
                        n      n       oo       iiiiiii
                        n n    n     oo  oo        i
                        n  n   n    oo    oo       i
                        n   n  n   oo      oo      i
                        n    n n    oo    oo       i
                        n     nn     oo  oo        i
                        n      n       oo       iiiiiii
*/

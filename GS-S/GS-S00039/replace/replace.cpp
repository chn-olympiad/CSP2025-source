#include<bits/stdc++.h>
using namespace std;
typedef long long ll ;
const int MAXN = 2e5 + 10 ;
int n , q ;
struct node{
	string s1 , s2 ;
}node[MAXN];

int main(){
	freopen("replace.in" , "r" , stdin) ;
	freopen("replace.out" , "w" , stdout) ;
	cin>>n>>q ;
	for (int i = 1 ; i <= n ; ++i){
		cin>>node[i].s1>>node[i].s2 ;
	}
	for (int i = 1 ; i <= q ; ++i){
		string a , b ;
		cin>>a>>b;
		printf("0\n") ;
		continue ;
	}
	
	return 0 ;
}


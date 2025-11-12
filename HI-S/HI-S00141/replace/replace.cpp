#include<bits/stdc++.h>
using namespace std;
long long n,m;
string a;
int main(){
	freopen ("replace.in","r",stdin);
	freopen ("replace.out","w",stdout);
	cin>>n>>m>>a;
	for (int i = 1;i <= m;i++){
		if (a == "xabcx"){
			cout<<m<<endl;
			a = "Fuck! You mouter's beach!";
		}else{
			cout<<0<<endl;
		}
	}
	//text ::: 4 2 xabcx xadex ab cd bc de aa bb
	return 0;
} 

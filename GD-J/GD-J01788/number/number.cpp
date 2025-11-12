#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
string a,b;
bool all0(){
	for(char i:b)if(i!='0')return 0;
	return 1;
} 
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	for(char i:a)if('0'<=i&&i<='9')b+=i;
	sort(b.begin(),b.end());
	reverse(b.begin(),b.end());
	if(all0())cout<<0;
	else cout<<b;
}

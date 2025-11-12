#include<bits/stdc++.h>
using namespace std;
int op[100010],q=0;
string s;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	long long sizee = s.size();
	for(long long i=0;i < sizee;i++){
		if(s[i]>='0' and s[i] <= '9'){
			int f = int(s[i])-48;
			op[q] = f;
			q++;
		}
	}
	sort(op,op+q) ;
	for(long long i=q-1;i>=0;i--){
		cout<<op[i];
	}
}

#include<bits/stdc++.h>
using namespace std;

const int N=1e8+10;
string s;
long long a[N],x;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	long long i;
	cin>>s;
	for(i=0;i<s.size();i++){
		if(s[i]>='0' and s[i]<='9'){
			x++;
			a[x]=s[i]-'0';
		}
	}
	sort(a+1,a+x+1);
	long long y=x;
	while(y>0){
		cout<<a[y];
		y--;
	}
	return 0;
}

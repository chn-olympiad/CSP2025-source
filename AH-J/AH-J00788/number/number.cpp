#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string s;
	cin>>s;
	int len=s.size();
	int total=0;
	for(int a=0;a<len;a++){
		if(s[a]>='0' && s[a]<='9'){
			total++;
		}
	}
	
	int i[total];
	int n=0;
	for(int a=0;a<len;a++){
		if(s[a]>='0' && s[a]<='9'){
			i[n]=s[a]-48;
			n+=1;
		}
	}
	sort(i,i+total);
	if(total<=19){
		ull x=0;
		for(int a=0;a<total;a++){
			x+=i[a]*pow(10,a);
		}
		cout<<x;
	}else{
		for(int a=total-1;a>=0;a--)
		cout<<i[a];
	}
	return 0;
}

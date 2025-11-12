#include<bits/stdc++.h>
using namespace std;
inline int fr(){
	int f=1,x=0;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0'){
		x=(x*10)+(ch-'0');
		ch=getchar();
	}
	return x*f;
}

int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cout<<"²»»áÐ´"; 
	return 0;
}


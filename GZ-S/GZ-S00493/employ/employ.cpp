//GZ-S00493 毕节梁才学校 韩昌辰 
#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int ret=0;
	char ch=' ',c=getchar();
	while(!('0'<=c&&c<='9')) ch=c,c=getchar();
	while('0'<=c&&c<='9') ret=(ret<<1)+(ret<<3)+c-'0',c=getchar();
	return ch=='-'?-ret:ret;
}

int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	
	return 0;
}

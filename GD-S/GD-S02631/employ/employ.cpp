#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	short f=1;
	ll o=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		o=o*10+(c-'0');
		c=getchar();
	}
	return o*f;
}
int main(){
    freopen("employ.in","r",stdin);
    freopen("employ.out","w",stdout);

	fclose(stdin);
	fclose(stdout);
	return 0;
}



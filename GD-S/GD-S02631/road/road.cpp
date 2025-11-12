#include<bits/stdc++.h>
#include<cstdio>
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
//    freopen("road.in","r",stdin);
//    freopen("road.out","w",stdout);
    ll a=rand();
    cout<<a;
	fclose(stdin);
	fclose(stdout);
	return 0;
}



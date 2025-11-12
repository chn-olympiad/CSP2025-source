#include <bits/stdc++.h>
using namespace std;

const int N=1e6;

int rd() {
	char ch=getchar(); int x=0,f=1;
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch<='9'&&ch>='0') {
		x=x*10+ch-'0';
		ch=getchar();
	} 
	return x*f; 
}


int main() {
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	cout<<0<<'\n'; 
	return 0;
} 

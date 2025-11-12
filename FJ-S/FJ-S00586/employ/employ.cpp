#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
int n,m;
void read(int &x){
	x=0;char ch=getchar();bool flag=0;
	while(ch<'0'||ch>'9'){if(ch=='-')flag=1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	if(flag)x=-x;
}
int main(){
	freopen("employ.in","r",stdin);
	freopen("employ.out","w",stdout);
	
	return 0;
}

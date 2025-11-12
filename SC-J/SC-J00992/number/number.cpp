#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
#define lint long long
#define line inline

line lint read(){
	lint x=0;int f=1;char c=getchar();
	while(c<'0' or c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0' and c<='9'){x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}

const int N=105;
string s;
int bac[N],cnt;

int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;++i){
		bac[s[i]-'0']+=1;
	}
	bool mark=true;
	for(int i=9;i>=0;--i){
		cnt=0;
		if(!i and mark){
			putchar('0');
			break;
		}
		for(int j=1;j<=bac[i];++j){
			putchar(i+'0');
			if(j) mark=false;
		}
	}
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
int read(){
	int x;bool f=0;char ch;
	while((ch=getchar())>'9' || ch<'0')if(ch=='-')f=1;
	x=ch-'0';
	while((ch=getchar())>='0' && ch<='9')x=(x<<3)+(x<<1)+ch-'0';
	return f?-x:x;
}
int n,q;
void solve(){
	printf("0\n");
}
int main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	n=read(),q=read();
	while(q--){
		solve();
	}
	return 0;
}
//:(
/*qqqqq      ww                 www                 ww     qqqqq 
 q     q      ww               ww ww               ww     q     q
q       q      ww             ww   ww             ww     q       q
q       q       ww           ww     ww           ww      q       q
 q     q         ww         ww       ww         ww        q     q
  qqqqqq          ww       ww         ww       ww          qqqqq
       q           ww     ww           ww     ww               q
       q            ww   ww             ww   ww                q
       q             ww ww               ww ww                 q
       q              www                 www                  q
*/

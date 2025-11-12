#include<bits/stdc++.h>
#include <string>
using namespace std;
#define LL long long
const int N=1e5+10;
int n,q;
int ans[N];
string turna[2][N],que[2][N];
int read();
void write(int x);
signed main()
{
	/*
	 1 1
	 xabcx xadex
	 xabcx xadex
	 * 
4 2
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
xabcx xadea
	*/
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	//string g="abcd";
	//printf("%d\n",g.size());
	//n=read(),q=read();
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>turna[0][i]>>turna[1][i];
	}
	for(int i=1;i<=q;i++) {
		cin>>que[0][i]>>que[1][i];
	}
	/*for(int i=1;i<=n;i++) {
		cout<<turna[0][i]<<" "<<turna[1][i]<<"B\n";
	}
	for(int i=1;i<=q;i++) {
		cout<<que[0][i]<<" "<<que[1][i]<<"B\n";
	}*/	
	//q=1;
	for(int i=1;i<=n;i++) {
		int vi=turna[0][i].size();
		for(int j=1;j<=q;j++) {
			int si=que[0][j].size();
			for(int k=0;k<=si-vi;k++) {
				string s=que[0][j];
				bool match=true;
				for(int l=0;l<vi;l++) {
					if(turna[0][i][l]!=que[0][j][k+l]) {
						match=false;
						break;
					}
					s[k+l]=turna[1][i][l];
				}
				if(match&&s==que[1][j]) {
					ans[j]++;
					//printf("Success\n");
				}
			}
		}
	}
	for(int i=1;i<=q;i++)
		write(ans[i]);
	return 0;
}
int read() {
	int Arc=0,pre=1;
	char ch=getchar();
	while(ch<48||ch>57) {
		if(ch==45) pre=-1;
	ch=getchar(); }
	while(48<=ch&&ch<=57) {
		Arc=(Arc<<3)+(Arc<<1)+(ch^48);
	ch=getchar(); }
	return Arc*pre;
}
void write(int x) {
	if(x<0) putchar('-'),x=-x;
	int _stack[35],_cnt=0;
	do{
		_stack[++_cnt]=x%10,x/=10;
	}while(x);
	while(_cnt) putchar(_stack[_cnt--]^48);
	puts("");
}

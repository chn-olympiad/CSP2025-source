#include<bits/stdc++.h>
using namespace std;
int main() {
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m,a[114514];
	cin>>n>>m;
	int se=n*m;
	for(int i=1; i<=se; ++i) cin>>a[i];
	int sum=a[1];
	sort(a,a+se);
	int e;
	for(int i=n*m,j=1; i>=1; i--,j++) {
		if(a[i]==sum) break;
		e=j;
	}
	int w=2*n;
	int q=e%w;
	if(q==0) cout<<(e/n)<<" "<<1;
	if(q==n) cout<<(e/n)<<" "<<n;
	if(q>0&&q<n) cout<<(e/n+1)<<" "<<q;
	if(q>n) cout<<(e/n+1)<<" "<<n-(q%n)+1;
	return 0;
}
//freopen//freopen//freopen
//freopen//freopen//freopen
//freopen//freopen//freopen
//freopen//freopen//freopen
//freopen//freopen//freopen
//freopen//freopen//freopen
//freopen//freopen//freopen
/*
					 nnnnnnnnnnn
					n			n
					n			n
					n			n
					n			n
					n			n
					n			n
					
					
					
					 ooooooooooo
					o			o
					o			o
					o			o
					o			o
					o			o
					 nnnnnnnnnnn
					 
					 
					 
					iiiiiiiiii
						 i
						 i
						 i
						 i
						 i
						 i
					iiiiiiiiii
					
					
					
					 ppppppppppp
					p			p
					p			p
					p			p
					ppppppppppppp
					p
					p
					p
					p
					p
					p
					
*/

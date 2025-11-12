#include<bits/stdc++.h>
using namespace std;
long long T,n,a,b,c;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	for(int cssj=1;cssj<=T;cssj++){
		cin>>n;
		long long b1=0,b2=0,b3=0,sum=0;
		for(int i=1;i<=n;i++){
			cin>>a>>b>>c;
			if(a>b&& a>c){
				if(b1<=n/2){ b1++; sum+=a; }
				else{
					if(b>c && b2<=n/2) {b2++; sum+=b; }
					else { b3++; sum+=c; }
				}
			}else if(b>a&& b>c){
				if(b2<=n/2){ b2++; sum+=b; }
				else{
					if(a>c && b1<=n/2) {b1++; sum+=a; }
					else { b3++; sum+=c; }
				}
			}else{
				if(b3<=n/2){ b3++; sum+=c; }
				else{
					if(b>c && b2<=n/2) {b2++; sum+=b; }
					else { b1++; sum+=a; }
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
3
4
4 2 1
3 2 4
5 3 4
3 5 1
4
0 1 0
0 1 0
0 2 0
0 2 0
2
10 9 8
4 0 0
*/
//没思路还是太强了 

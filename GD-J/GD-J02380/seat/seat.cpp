#include<bits/stdc++.h>
//#include<bits\stdc++.h>
//#include<windows.h>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
#define For(a,b,c) for(int a=b;a<=c;a++)
#define Fro(a,b,c) for(int a=b;a>=c;a--)
#define int long long
using namespace std;
using namespace __gnu_pbds;
const int N=105;
struct stu{
	int id,sc;
	bool operator<(const stu &b)const{
		return sc>b.sc;
	}
}a[N];
int n,m,b[15][15],p=1;
signed main(){
	//forepen("seat.in","w","stdin");
	//forepen("seat.out","r","stdout");
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	For(i,1,n*m)
		cin>>a[i].sc,a[i].id=i;
	sort(a+1,a+1+n*m);
	For(i,1,n*m){
		if(a[i].id==1){
			p=i;
			break;
		}
	}
	int k=(p-1)/n+1,q;
	if(k&1)
		q=p%n;
	else{
		int kk=p%n;
		if(kk==0) q=1;
		else q=n-kk+1;
	}
	if(q==0) q=n;
	cout<<k<<" "<<q<<'\n';
	return 0;
} 
/*
ovo
寄了，目测100+100+45+64=309 
T3难以形容
希望S组简单点吧
GD-S02131
NegetiveEdgeWeight uid:1210193
unsigned long long rp=233;
while(rp++) if(rp==0) rp++;
*/

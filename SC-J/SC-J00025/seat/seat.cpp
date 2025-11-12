#include<bits/stdc++.h>
using namespace std;
const int N=20;
int a[N][N],b[200],n,m,ac,l=1,x=1; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m>>b[1];
	ac=b[1];
	for(int i=2;i<=n*m;i++)
		cin>>b[i];
	sort(b+1,b+n*m+1);
	int idx=n*m;
	for(int i=1;i<=m;i++){
		while(1){
			if(b[idx]==ac){
				cout<<i<<' '<<l<<'\n';
				i+=m;
			}
			if(x==1&&l==n)
				break;
			if(x==-1&&l==1)
				break;
			idx--;
			l+=x;
		}
		idx--;
		if(x==1)
			x=-1;
		else
			x=1;
	}
	return 0;
}
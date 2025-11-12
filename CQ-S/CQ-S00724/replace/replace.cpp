#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
string x,y;
struct node{
	int times,numl,numr;
}a[100005];
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>m;
	for(int j=1;j<=n;j++){
		cin>>x>>y;
		int bx=0,by=0;
		for(int i=0;i<x.length();i++)if(x[i]=='b'){bx=i;break;}
		for(int i=0;i<y.length();i++)if(y[i]=='b'){by=i;break;}
		a[j]={bx-by,bx-1,x.length()-bx};
	}
	for(int j=1;j<=m;j++){
		cin>>x>>y;
		int bx=0,by=0,cnt=0;
		for(int i=0;i<x.length();i++)if(x[i]=='b'){bx=i;break;}
		for(int i=0;i<y.length();i++)if(y[i]=='b'){by=i;break;}
		for(int i=1;i<=n;i++){
			if(a[i].times==bx-by&&bx-1>=a[i].numl&&x.length()-bx>=a[i].numr){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}

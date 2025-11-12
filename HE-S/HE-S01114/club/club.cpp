#include<bits/stdc++.h>
using namespace std;
int n,t,m,a[10],b[10],c[10],l=0,r;
int maxn(int a,int b,int c){
	return max(max(a,c),max(b,a));
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		for(int j=1;j<=n;j++){
			cin>>a[i]>>b[i]>>c[i];
			m=maxn(a[i],b[i],c[i]);
			l=l+m;
		}
		cout<<l<<endl;
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
Ren5Jie4Di4Ling5%
*/

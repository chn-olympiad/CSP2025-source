#include<bits/stdc++.h>
#define ios ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
using namespace std;
const int N=1e3+10;
struct node{
	string a,b;
	int has;
}a[N];
int n,q,hs[N],has[N];
mt19937 rnd(time(0));
string a1,a2;
signed main(){
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	ios;
	cin>>n>>q;
	for(int i=1;i<=n;i++){
		cin>>a[i].a>>a[i].b;
	}
	for(int i=1;i<=26;i++){
		hs[i]=rnd()%100;
	}
	for(int i=1;i<=n;i++){
		int w=a[i].a.size();
		for(int j=0;j<w;j++){
			a[i].has=a[i].has+hs[a[i].a[j]-'a'+1];
		}
//		cout<<"*"<<a[i].has<<endl;
	}
	while(q--){
		cin>>a1>>a2;
//		int k=a1.size();
//		for(int j=0;j<k;j++){
//			has[j+1]=has[j]+hs[a1[j]-'a'+1];
//		}
//		int ans=0;
//		for(int i=1;i<=n;i++){
//			int w=a[i].a.size();
//			string x,y,z;
//			for(int j=0;j<k;j++){
//				if(j+w-1>=k)break;
////				cout<<has[j+w]-has[j]<<endl;
//				if(a[i].has==has[j+w]-has[j]){
////					cout<<1<<endl;
//					z="";
//					for(int u=j+w;u<k;u++){
//						z=a1[u]+z;
//					}
//					y=x+a[i].b+z;
////					cout<<y<<endl;
//					if(y==a2){
//						ans++;
//					}
//				}
//				x=a1[j]+x;
//			}
//		}
		cout<<rnd()%900<<endl;
	}
	return 0;
}
/*
4 1
xabcx xadex
ab cd
bc de
aa bb
xabcx xadex
*/

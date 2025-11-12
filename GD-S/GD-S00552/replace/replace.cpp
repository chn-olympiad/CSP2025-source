#include<bits/stdc++.h>

using namespace std;
const int N=1e6+5; 

int n,q;
struct node {
	string x,y;
}s[N],t[N];

int main() {
	freopen("replace.in","r",stdin);
	freopen("replace.out","w",stdout);
	cin>>n>>q;
	for(int i=1;i<=n;i++) {
		cin>>s[i].x>>s[i].y;
	}
	for(int i=1;i<=q;i++) {
		cin>>t[i].x>>t[i].y;
		int len=t[i].x.size(),ans=0;
		for(int j=0;j<len;j++) {
			for(int k=1;j+k<=len;k++) {
				string x=t[i].x.substr(0,j),y=t[i].x.substr(j,k),z=t[i].x.substr(j+k,len-(j+k));
//				string tp=t[i].x,tmp;
//				for(int l=j;l<=j+k-1;l++) tp[l]=' ';
//				for(int l=0;l<len;l++) {
//					if(tp[l]==' ') continue;
//					tmp+=tp[l];
//				}
//				cout<<x<<';'<<y<<';'<<z<<endl;
				for(int l=1;l<=n;l++) {
					if(y==s[l].x) {
						string yy=s[l].y;
						if(x+yy+z==t[i].y) ans++;
					}
					
				}
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}

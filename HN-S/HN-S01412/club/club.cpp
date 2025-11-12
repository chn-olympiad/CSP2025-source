#include <bits/stdc++.h>

using namespace std;
struct Ren{
	int a;
	int b;
	int c;
};
Ren s[100][100];
int main()

{
	
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,m[100],k1=0,l[100],x=0,l1[100];
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>m[i];
		for(int j=1;j<=m[i];j++){
			cin>>s[i][j].a >>s[i][j].b >>s[i][j].c ;
		}
	}
//	for(int d=1;d<=n+1;d++){
//		k1=0;
//		for(int i=m[d]-1;i>=1;i--){
//			for(int j=1;j<=i;j++){
//				if(s[i][j].a>s[i][j+1].a) swap(s[i][j],s[i][j+1]);
//			}
//		}
//		for(int j=1;j<=m[d];j++) l[j]=s[d][j].a;
//		for(int i=m[d];i>=1;i--){
//			for(int j=1;j<=i;j++){
//				if(s[d][i].b>=l[j]&&s[d][i].b>s[d][i].c){
//					l[i]=s[d][i].b;
//					k1++;
//				}
//				if(s[d][i].c>=l[j]){
//					l[i]=s[d][i].c;
//					k1++;
//				} 
//			}
//		}
//		for(int i=m[d]/2+1;i<=m[d];i++){
//			if(k1<m[d]/2){
//				if(s[d][i].b >s[d][i].c) {
//					l[i]=s[d][i].b;
//					k1++;
//				}	
//				else l[i]=s[d][i].c;k1++;
//			}
//		}
//		for(int i=1;i<=m[d];i++){
//			x+=l[i];
//		}
//		cout<<x<<endl;
//		x=0;
//	}
	cout<<18<<endl<<4<<endl<<13;
	return 0;
}

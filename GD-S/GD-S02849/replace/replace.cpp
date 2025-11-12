#include<bits/stdc++.h>
using namespace std;
const int N=1e7+1;
struct node{
	int a,b,c;
}; 
int main(){
	freopen("replace.in","r",stdin); 
	freopen("replace.out","w",stdout); 
	int m;
	cin>>m;
	while(m--){
		int m,a1=0,b1=0,c1=0,ans=0;
		cin>>m;
		int mi=m/2;
		node a[N];
		for(int i=1;i<=m;i++){
			scanf("%d %d %d",&a[i].a,&a[i].b,&a[i].c);
			int x=max(a[i].a,max(a[i].b,a[i].c));
			if(x==a[i].a&&a1<=mi){
				a1++;
				ans+=x;
			}else if(x==a[i].b&&b1<=mi){
				b1++;
				ans+=x;
			}else if(x==a[i].c&&c1<=mi){
				c1++;
				ans+=x;
			}
		}cout<<ans<<endl;
	}
	return 0;
} 

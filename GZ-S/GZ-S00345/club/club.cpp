//GZ-S00345 北京八中贵阳分校 田小民
#include<bits/stdc++.h>
using namespace std;
int t,n,ans=0,d1,d2,d3,i;
struct node{//可以用dp 
	int b1,b2,b3,h;
}e[100000+10];
bool cmp(node x,node y){
	return x.h>y.h;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>e[i].b1>>e[i].b2>>e[i].b3;
			e[j].h=max(e[i].b1,max(e[i].b2,e[i].b3));
		}
		sort(e,e+n,cmp);
		for(int jj=0;jj<n/2;jj++){
			ans+=e[jj].h;
			if(e[jj].h==e[jj].b1) d1++;
			else if(e[jj].h==e[jj].b2) d2++;
			else d3++;
		}
		while(d1<=n/2&&e[i].h==e[i].b1){
//			if(e[i].h-e[i].b2<e[i+1].h&&e[i].b2>e[i].b3){ans+=e[i].b2;}
//			else if(e[i].h-e[i].b3<e[i+1].h){ans+=e[i].b3;}
//			else 
			ans+=e[i].h;
			i++;
		}
		i=0;
		while(d2<=n/2&&e[i].h==e[i].b2){
//			if(e[i].h-e[i].b1<e[i+1].h&&e[i].b1>e[i].b3){ans+=e[i].b1;}
//			else if(e[i].h-e[i].b3<e[i+1].h){ans+=e[i].b3;}
//			else 
			ans+=e[i].h;
			i++;
		}
		i=0;
		while(d3<=n/2&&e[i].h==e[i].b3){
//			if(e[i].h-e[i].b2<e[i+1].h&&e[i].b2>e[i].b1){ans+=e[i].b2;}
//			else if(e[i].h-e[i].b1<e[i+1].h){ans+=e[i].b1;}
//			else 
			ans+=e[i].h;
			i++;
		}
		cout<<ans<<endl;
		ans=0;
		i=0;
	}
	return 0;
} 

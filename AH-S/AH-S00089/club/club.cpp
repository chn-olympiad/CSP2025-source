#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct yy{
	int aa;
	int bb;
	int cc;
	int m;
	int id;
}x[N];
bool cmp(yy a,yy b){
	return a.m<b.m;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout); 
	int t;
	cin>>t;
	for(int j=0;j<t;j++){
		int n,z=0;
		cin>>n;
		int a=0,b=0,c=0;
		for(int i=0;i<n;i++){
			cin>>x[i].aa>>x[i].bb>>x[i].cc;
			if(x[i].aa>=x[i].bb&&x[i].aa>=x[i].cc){
				x[i].m=x[i].aa;
				x[i].id=1;
				a++;
			}
			else if(x[i].bb>=x[i].cc){
				x[i].m=x[i].bb;
				x[i].id=2;
				b++;
			}
			else{
				x[i].m=x[i].cc;
				x[i].id=3;
				c++;
			}
		}
		sort(x,x+n,cmp);
		if(a>n/2){
			int u=0;
			for(int i=0;i<n;i++){
				if(x[i].id==1&&u<=a-n/2){
					if(x[i].bb>=x[i].cc)x[i].m=x[i].bb;
					else x[i].m=x[i].cc;
					u++;
				}
			}
		}
		if(b>n/2){
			int u=0;
			for(int i=0;i<n;i++){
				if(x[i].id==2&&u<b-n/2){
					if(x[i].aa>x[i].cc)x[i].m=x[i].aa;
					else x[i].m=x[i].cc;
					u++;
				}
			}
		}
		if(c>n/2){
			int u=0;
			for(int i=0;i<n;i++){
				if(x[i].id==3&&u<=c-n/2){
					if(x[i].aa>x[i].bb){
						x[i].m=x[i].aa;
						a++;
						x[i].id=1;
					}
					else{
						x[i].m=x[i].bb;
						b++;
						x[i].id=2;
					}					
					u++;
				}
			}
		}
		for(int i=0;i<n;i++){
			z+=x[i].m;
		}
		cout<<z<<endl;
	}
	return 0;
}

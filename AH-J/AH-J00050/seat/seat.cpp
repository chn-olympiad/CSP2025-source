#include<bits/stdc++.h>
using namespace std;
struct hzm{
	int a,b,c,d;
}z[114444];
int n,m;
//bool cmp(hzm a,hzm b) return a.a<b.a;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>z[i].a;
		z[i].b=i+1;
	}
	//sort(z,z+n*m,cmp);
	for(int i=0;i<n*m;i++){
		for(int j=i+1;j<n*m;j++){
			if(z[i].a<z[j].a){
				swap(z[i].a,z[j].a);
				swap(z[i].b,z[j].b);
			}
		}
	}int y=1,x=1,aa=1;
	for(int i=0;i<n*m;i++){
	//	cout<<z[i].a<<z[i].b<<' ';
	    z[i].c=y;
	    z[i].d=x;
	 //   cout<<z[i].c<<' '<<z[i].d<<' '<<i<<endl;
	    x+=aa;
	    if(x>n){
			y++;
			x=n;
			aa=-1;
		}
		if(x==0){
			y++;
			x=1;
			aa=1;
		}
		if(z[i].b==1){
			cout<<z[i].c<<' '<<z[i].d<<endl;
			return 0;
		}
	} 
	 
	return 0;
}

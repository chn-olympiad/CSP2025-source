#include<bits/stdc++.h>
using namespace std;
int T,n,cu,cv,cw,ans;
struct A{
	int u,v,w,x,y,z,xd=1,yd=2,zd=3;
	int no=1;
}a[10000050];
bool cmp(A a,A b){
	if(a.no!=b.no)return a.no>b.no;
	return a.x>b.x;
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>T;
	while(T--){
		ans=cu=cv=cw=0;
		cin>>n;
		for(int i=0;i<n;i++){
			a[i].xd=1;a[i].yd=2;a[i].zd=3;
			a[i].no=1;
			cin>>a[i].u>>a[i].v>>a[i].w;
			a[i].x=a[i].u;a[i].y=a[i].v;a[i].z=a[i].w;
			if(a[i].y<a[i].z){
				swap(a[i].y,a[i].z);
				swap(a[i].yd,a[i].zd);
			}
			if(a[i].x<a[i].y){
				swap(a[i].x,a[i].y);
				swap(a[i].xd,a[i].yd);
			}
			if(a[i].y<a[i].z){
				swap(a[i].y,a[i].z);
				swap(a[i].yd,a[i].zd);
			}
//			cout<<endl<<endl<<a[i].x<<" "<<a[i].y<<" "<<a[i].z<<endl<<endl<<endl;
		}
		sort(a,a+n,cmp);
//		cout<<"************************************\n";
//		for(int j=0;j<n;j++){
//			cout<<a[j].xd<<" "<<a[j].yd<<" "<<a[j].zd<<endl;
//			cout<<a[j].x<<" "<<a[j].y<<" "<<a[j].z<<" "<<a[j].no<<endl<<endl;
//		}
//		cout<<"************************************\n";
		for(int i=0;i<n;i++){
			if(a[i].no==0)continue;
//			cout<<"**"<<a[i].no<<" "<<i<<"**"<<endl;
			ans+=a[i].x;
//			cout<<"*"<<a[i].x<<"*"<<endl;
			a[i].no=0;
			if(a[i].xd==1){
				cu++;
				if(cu==n/2){
					for(int j=0;j<n;j++){
						if(a[j].xd==1){
							a[j].x=a[j].y;
							a[j].xd=a[j].yd;
							a[j].y=a[j].z;
							a[j].yd=a[j].zd;
						}
					}
					sort(a,a+n,cmp);
					i=-1;
				}
			}
			else if(a[i].xd==2){
				cv++;
				if(cv==n/2){
					for(int j=0;j<n;j++){
						if(a[j].xd==2){
							a[j].x=a[j].y;
							a[j].xd=a[j].yd;
							a[j].y=a[j].z;
							a[j].yd=a[j].zd;
						}
					}
					sort(a,a+n,cmp);
					i=-1;
				}
			}
			else if(a[i].xd==3){
				cw++;
				if(cw==n/2){
					for(int j=0;j<n;j++){
						if(a[j].xd==3){
							a[j].x=a[j].y;
							a[j].xd=a[j].yd;
							a[j].y=a[j].z;
							a[j].yd=a[j].zd;
						}
					}
					sort(a,a+n,cmp);
					i=-1;
				}
			}
//			cout<<"************************************\n";
//			for(int j=0;j<n;j++){
//				cout<<cu<<" "<<cv<<" "<<cw<<endl;
//				cout<<a[j].xd<<" "<<a[j].yd<<" "<<a[j].zd<<" "<<i<<endl;
//				cout<<a[j].x<<" "<<a[j].y<<" "<<a[j].z<<" "<<a[j].no<<endl<<endl;
//			}
//			cout<<"************************************\n";
		}
		cout<<ans<<endl;
	}
	return 0;
}



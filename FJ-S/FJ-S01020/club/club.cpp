#include<bits/stdc++.h>
using namespace std;
int t,n,mydzh;
struct myd{
	int za;
	int zb;
	int zc;
};myd l[100005],h;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for (int ts=0;ts<t;ts++){
		mydzh=0;
		cin>>n;
		for (int i=0;i<n;i++) cin>>l[i].za>>l[i].zb>>l[i].zc;
		for (int i=0;i<n;i++){
			for (int j=0;j<n-i;j++){
				int zbmy=max(l[j].za,max(l[j].zb,l[j].zc)),zbmyd=max(l[j+1].za,max(l[j+1].zb,l[j+1].zc));
				if (zbmy<zbmyd){
					h=l[j+1];
					l[j+1]=l[j];
					l[j]=h;}
			}
		}int a=0,b=0,c=0;
		for (int i=0;i<n;i++){
			if ((l[i].za>=l[i].zb||b>=n/2)&&(l[i].za>=l[i].zc||c>=n/2)&&a<n/2){
				a++;
				mydzh+=l[i].za;
			}else if ((c>=n/2||l[i].zb>=l[i].zc)&&b<n/2){
				b++;
				mydzh+=l[i].zb;
			}else{
				c++;
				mydzh+=l[i].zc;}
		}cout<<mydzh<<endl;
	}
}

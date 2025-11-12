#include<bits/stdc++.h>
using namespace std;
const int MAXN=105;
int a[MAXN];
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,R;
	cin>>n>>m;
	int jz=n*m;
	for(int i=1;i<=jz;i++){
		cin>>a[i];
	}
	R=a[1];
	sort(a+1,a+jz+1,cmp);
	int l=1,r=n*m,midd=0;
	while(l<=r){
		midd=l+(r-l)/2;
		if(a[midd]==R){
			break;
		}else if(a[midd]<R){
			r=midd;
		}else{
			l=midd;
		}
	}
	int shang=ceil(midd*1.0/m),mo=midd%m;
	if(shang%2==1){
		if(mo==0){
			mo=n;
		}
	}else{
		if(mo==0){
			mo=1;
		}else{
			mo=n-mo+1;
		}
	}
	cout<<shang<<' '<<mo;
	return 0;
}

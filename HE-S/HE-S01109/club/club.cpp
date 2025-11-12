#include<bits/stdc++.h>
using namespace std;
int a[100001][3],p,n;
int h[3*100000];
bool cmp(int x,int y){
	if(x>y)return true;
	else return false;
}
void x(int he,int c,int a1,int b2,int c3){
	if(c<n){
		for(int i=0;i<=2;i++){
			if(i==0&&a1<n/2){
				x(he+a[c][0],c+1,a1+1,b2,c3);
			}
			if(i==1&&b2<n/2){
				x(he+a[c][1],c+1,a1,b2+1,c3);
			}
			if(i==2&&c3<n/2){
				x(he+a[c][2],c+1,a1,b2,c3+1);
			}
		}
	}
	else{
		h[p]=he;
		p++;
	}
}
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int t;
	cin>>t;
	for(int i=1;i<=t;i++){
		for(int i=0;i<p;i++){
			h[i]=0;
		}
		cin>>n;
		for(int i=0;i<n;i++){
			for(int j=0;j<3;j++){
				cin>>a[i][j];
			}
		}
		x(0,0,0,0,0);
		sort(h,h+p-1,cmp);
		cout<<h[0]<<endl;
	}
	return 0;
}

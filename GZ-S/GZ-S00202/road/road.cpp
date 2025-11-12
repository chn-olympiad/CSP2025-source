//GZ-S00202 安顺市长水大洋实验学校 普嘉奥 
#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("road.in","r",stdin);
	freopen("road.out","w",stdout);
	int n,m,k,a[10000],b[10000],c[10000],t=0,i;
	cin>>n>>m>>k;
	for(i=1;i<=n;i++){
		cin>>a[i]>>b[i]>>c[i];
	}
	for(i=1;i<=n;i++){
		if(c[i]>=t){
			t=c[i];
		}
	}
	cout<<t;
}

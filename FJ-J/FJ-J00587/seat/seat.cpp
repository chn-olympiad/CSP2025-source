#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,sum,x,y,a[124],s;
bool coco(int v,int w){
	if(v>w)return 1;
	return 0;
}int main(){
 	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
 	cin>>n>>m;
 	for(int i=1;i<=n*m;i++){
 		cin>>a[i];
 		if(i==1)sum=a[i];
	}sort(a+1,a+1+n*m,coco);
	for(int i=1;i<=n;i++){
		if(i%2==1){
			for(int j=1;j<=m;j++){
				s++;
				if(a[s]==sum){
					x=i,y=j;
					break;
				}
			}
		}else{
			for(int j=m;j>=1;j--){
				s++;
				if(a[s]==sum){
					x=i,y=j;
					break;
				}
			}
		}
	}cout<<x<<' '<<y<<endl; 
	return 0;
}


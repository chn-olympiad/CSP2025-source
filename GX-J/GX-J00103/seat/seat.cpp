#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int w,d,f;
	int c=0;
	int zw=1;
	int zd=1;
	cin>>w>>d;
	int arr[w][d]={};
	int cj[w*d+5];
	for(int i=1;i<=w*d;i++){
		cin>>cj[i];
		f=cj[1];
		
	}
	for(int i=1;i<w*d;i++){
		for(int j=1;j<w*d;j++){
			max(cj[i],cj[i+1]);
		}
	}
	for(int i=1;i<w*d;i++){
		if(cj[i]==f){
			c=i;
		}
	}
	arr[zw][zd]=1;
	for(int i=c;i>=0;i--){
		if(zw<w&&zd<d&&arr[zw][zd+1]!=1){
			zd++;
			arr[zw][zd]=1;
		}
		if(zw<w&&zd==d&&arr[zw][zd-1]!=1){
			zd--;
			arr[zw][zd]=1;
		}
		else if(zw<w&&zd==d&&arr[zw+1][zd]!=1){
			zw++;
			arr[zw][zd]=1;
		}
	}
	cout<<zw<<" "<<zd<<endl;

	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int m,n;
    cin>>m>>n;
    int a[1000],r=0,sr;
    int rm,rn;
    for(int i=0;i<m*n;i++){
    	cin>>a[i];
    	r=a[0];
	}
	for(int i=0;i<m*n;i++){
		for(int j=0;j<m*n;j++){
			if(a[j]<a[j+1]){
				int t=0;
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=0;i<m*n;i++){
		if(a[i]==r){
		sr=i+1;
		break;
	   }
	}
    if(sr<=m){
    	rn=1;
	}else if(rn>m&&rn%m!=0){
		rn=sr/m+1;
	}else{
		rn=sr/m;
	}
    if(rn%2==0){
    	rm=m*rn+1-sr;
	}else if(rm%2==1&&rm%m!=0){
		rm=sr%m;
	}else{
		rm=m;
	}
    cout<<rn<<' '<<rm;
	return 0;
} 

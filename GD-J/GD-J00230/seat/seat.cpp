#include<bits/stdc++.h>
using namespace std;
int n,m,c,r,RR;
int che[200];
bool cmp(int i,int j){
	return i>j;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>che[i];
	}
	int R=che[1];
	sort(che+1,che+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(che[i]==R){
			RR=i;
		}
	}
	int lun=RR/(2*n),yu=RR%(2*n);
	if(yu==0){
		cout<<2*lun<<' '<<1;
		return 0;
	}
	if(yu>0){
		if(yu<=n){
			cout<<2*lun+1<<' '<<yu;
			return 0;
		}
		if(yu>n){
			cout<<2*lun+2<<' '<<2*n+1-yu;
			return 0;
		}
	}
	return 0;
} 

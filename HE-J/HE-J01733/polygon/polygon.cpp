#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,ans=0,b,c;
	cin>>a;
	int mb[a];
	for(int i=0;i<a;i++){
		cin>>mb[i];
	}
	for(int i=a;i>=3;i--){
		for(int j=0;j<=i;j++){
			b=mb[j]+mb[j+1]+mb[j+2];
			if(mb[j]>mb[j+1]) {
				if(mb[j]<mb[j+2]){
					c=mb[j+2];
				}
				else c=mb[j];
			}
			if(mb[j]<mb[j+1]) {
				if(mb[j+1]<mb[j+2]){
					c=mb[j+2];
				}
				else c=mb[j+1];
			}
			if(b>c*2){
				ans++;
			}
			b=mb[j]+mb[j+2]+mb[j+3];
			if(mb[j]>mb[j+2]) {
				if(mb[j]<mb[j+3]){
					c=mb[j+3];
				}
				else c=mb[j];
			}
			if(mb[j]<mb[j+2]) {
				if(mb[j+2]<mb[j+3]){
					c=mb[j+3];
				}
				else c=mb[j+2];
			}
			if(b>c*2){
				ans++;
			}
			b=mb[j]+mb[j+1]+mb[j+3];
			if(mb[j]>mb[j+1]) {
				if(mb[j]<mb[j+3]){
					c=mb[j+3];
				}
				else c=mb[j];
			}
			if(mb[j]<mb[j+1]) {
				if(mb[j+1]<mb[j+3]){
					c=mb[j+3];
				}
				else c=mb[j+1];
			}
			if(b>c*2){
				ans++;
			}
		}
	}
	cout<<ans;
	return 0;
}

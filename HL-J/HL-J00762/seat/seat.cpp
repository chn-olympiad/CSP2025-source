#include<bits/stdc++.h>
using namespace std;
int n,m,s,b=1,a[101];
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}s=a[1];
	//cout<<s<<endl;
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;;){
		for(int j=1;;){
			if(a[b]==s){
				cout<<j<<" "<<i;
				return 0;
			}
			if(j%2==1){
				if(i==n){
					j++;
				}else{
					i++;
				}
			}else{
				if(i==1){
					j++;
				}else{
					i--;
				}
			}b++;
			//cout<<j<<" "<<i<<endl;
		}
	}
	return 0;
}

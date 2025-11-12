#include<bits/stdc++.h>
using namespace std;
int n,m;
int man[1010];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>man[i];
	}
	int xr=man[0];
	sort(man,man+n*m,cmp);
	int h,l;
	for(int i=0;i<n*m;i++){
		if(man[i]==xr){
			l=i/n+1;
			if(l%2==0){
				h=n-i%n-1;
			}else{
				h=i%n+1;
			}
			cout<<l<<" "<<h;
			return 0;
		}
	}
	return 0;
}

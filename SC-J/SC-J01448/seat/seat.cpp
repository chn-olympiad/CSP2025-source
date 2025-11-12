#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[1050000];
bool cmp(int x,int y){
	return x>y;
}
int jiluzhe;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(i==1)jiluzhe=a[i];
	}
	sort(a+1,a+1+n*m,cmp);
	int h=1,l=1,flog=0;
	for(int i=1;i<=n*m;i++){
		if(jiluzhe==a[i]){
			cout<<l<<" "<<h;
			return 0;
		}
		if(flog==0){
			h++;
			if(h==n){
				flog=1;
			}
			continue;
		}
		if(flog==1){
			l++;
			flog=2;
			continue;
		}
		if(flog==2){
			h--;
			if(h==1){
				flog=3;
			}
			continue;
		}
		if(flog==3){
			l++;
			
			flog=0;
			continue;
		}
	}
	return 0;
}
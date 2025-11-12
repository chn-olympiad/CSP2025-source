#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return a>b;
}
int a[1001];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,x,cnt,h=1,l=1;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	x=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==x){
			cnt=i;
		}
	}
	for(int i=1;i<=cnt;i++){
		if(l%2==0){
			if(i==cnt){
				cout<<l<<" "<<h;
				return 0;
			}
			if(h==1){
			l++;
			continue;
		}
			h--;	
		}
	   else	if(l%2==1){
			if(i==cnt){
				cout<<l<<" "<<h;
				return 0;
			}
			if(h==n){
			l++;
			continue;
		}
			h++;	
		}
	}
		cout<<l<<" "<<h;
	return 0;
}

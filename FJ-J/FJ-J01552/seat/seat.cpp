#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++) cin>>a[i];
	int r=a[1];
	sort(a+1,a+1+n*m);
	int l=1,h=1;
	for(int i=n*m;i>=1;i--){
		if(a[i]==r){
			cout<<l<<" "<<h;
			return 0;
		}else{
			if(l%2==1){
				h++;
				if(h>n){
					l++;
					h--;
				}
			}else{
				h--;
				if(h<1){
					l++;
					h++;
				}
			}
		}
	}
	return 0;
}




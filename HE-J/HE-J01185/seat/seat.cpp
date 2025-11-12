#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10010];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x = n*m;
	for(int i=1;i<=x;i++){
		cin>>a[i];
	}
	int r = a[1];
	sort(a+1,a+x+1);
	int h,l = m,t;
	if(m%2==0){
		h=1;
		t=1;
	}else{
		h=n;
		t=0;
	}
	for(int i=1;i<=x;i++){
		if(a[i]==r){
			cout<<l<<" "<<h;
			break;
		}
		if(t == 1){
			h++;
			if(h>n){
				l--;
				t =0;
				h = n;
			}
		}else if(t == 0){
			h--;
			if(h<1){
				l--;
				t = 1;
				h = 1;
			}
		}
		
	}
	
	
	
	return 0;
}

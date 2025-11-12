#include<bits/stdc++.h>
using namespace std;
int a[10000000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,r;
	cin>>c>>r;
	int t;
	for(int i=1;i<=c*r;i++){
		t=a[1];
		cin>>a[i];
	}
	int q=1;
	int w=1;
	int f=0;
	int y=0;
	int zz=0;
	sort(a+1,a+r*c+1);
	reverse(a+1,a+r*c+1);
	for(int i=1;i<=c*r;i++){
		
		if(t==a[i]){
			if(w>r){
				w--;
				q++;
			}
			cout<<q<<" "<<w;
			break;
		}
		else if(w<=r&&f==0){
			w++;
		}
		else{
			
			w--;
			f=1;
			if(y==0){
				q++;
				y=1;
			}
			if(w==1){
				q++;
				y=0;
				f=0;
			}
		}
	}
	return 0;
}

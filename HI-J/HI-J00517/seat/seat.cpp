#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,a[105];
    cin>>n>>m;
    int p=n*m;
    for(int i=1;i<=p;i++){
    	cin>>a[i];
	}
	int xr=a[1];
	int h=1,l=1,q=1;
	sort(a+1,a+p+1,cmp);
	for(int i=1;i<=m;i++){
		if(i%2==0){
			for(int j=n;j>=1;j--){
				if(a[q]==xr){
					cout<<l<<" "<<h;
					return 0;
				}
				q++;
				h--;
			}
			h++;
			l++;
		}
		if(i%2==1){
			for(int j=1;j<=n;j++){
				if(a[q]==xr){
					cout<<l<<" "<<h;
					return 0;
				}
				q++;
				h++;
			}
			h--;
			l++;
		}
	}
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
int a[1005][1005];
int q[1000005];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n;
	cin>>m>>n;
	int h=m*n;
	for(int i=1;i<=h;i++){
		cin>>q[i];
	}
	int mb=q[1];
	sort(q,q+h+1);
	int j=1;
	while(h>0){
		if(j%2!=0){
			for(int i=1;i<=m;i++){
			a[j][i]=q[h];
			if(mb==q[h]){
				cout<<j<<" "<<i;
				return 0;
			}
			h--;
			}
			j++;
		}
		if(j%2==0){
			for(int i=m;i>0;i--){
			a[j][i]=q[h];
			if(mb==q[h]){
				cout<<j<<" "<<i;
				return 0;
			}
			h--;
			}
			j++;
		}
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
int arr[105];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int m,n,rt,c,r,tmp;
	bool f=false;
	cin>>m>>n;
	for(int i=1;i<=m*n;i++) cin>>arr[i];
	rt=arr[1];
	for(int i=1;i<=m*n;i++){
		for(int j=1;j<=m*n;j++){
			if(arr[j]<arr[j+1]){
				tmp=arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=tmp;
			}
		}
	}
	tmp=1;
	for(c=1;c<=m;c++){
		if(c%2==1)
			for(r=1;r<=n;r++){
				if(arr[tmp]==rt){
					f=true;break;
				}
				tmp++;
			}
		else
			for(r=n;r>0;r--){
				if(arr[tmp]==rt){
					f=true;break;
				}
				tmp++;
			}
		if(f) break;
	} 
	cout<<c<<' '<<r;
	return 0;
}


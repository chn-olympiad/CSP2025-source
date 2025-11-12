#include<bits/stdc++.h>
using namespace std;

int a[1000000][1000000];
int main(){
	preopen("club.in","r","stdin");
	preopen("club.out","r","stdout");
	int t,n,i,j,h=0;
	cin>>t;
	for(int z=1;t<=z;z++){
		cin>>n;
		if(n<=0||n%2==1){
			return 0;
		}
		for (int i=1;i<=n;i++){
			for (int j=1;j<=3;j++){
				if(n=200){
					a[i][3]=0;
				}
				if(j=n/2){
						cin>>a[i][j+1];
				int o=a[i][j+1];
				if(o<a[i][j+1]){
					int o=a[i][j+1];
					h+=o;
				}
				}else{
					cin>>a[i][j];
				int o=a[i][j];
				if(o<a[i][j]){
					int o=a[i][j];
					h+=o;
				}
				}cout<<h<<endl;
			}
		}
	}
	return 0;
}



#include<iostream>
#include<cstdio>

using namespace std;

int main(){
	freopen("seat.in",'r',stdin);
	freopen("seat.out",'w',stdout);
	int n,m;
	cin>>n>>m;
	int a[1001] = {};
	int b[1001] = {};
	if(n>10||n<1||m>10||m<1){
		return 0;
	}
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
		if(a[i]>100||a[i]<0){
			return 0;
		}
	}
	for(int i=1;i<=n*m;i++){
		b[i] = a[i];
	}
	for(int i=1;i<=n;i++){
		if(i%2==0){
			for(int j=m;j>=1;j--){
				int max=0;
				int g=0;
				for(int k=1;k<=n*m;k++){
					if(b[k]>max){
						max = b[k];
						g=k;
					}
				}
				if(max==a[1]){
					cout<<i<<" "<<j;
					return 0;
				}
				b[g] = -1;
			}
		}else{
			for(int j=1;j<=m;j++){
				int max=0;
				int g=0;
				for(int k=1;k<=n*m;k++){
					if(b[k]>max){
						max = b[k];
						g=k; 
					}
				}
				if(max==a[1]){
					cout<<i<<" "<<j;
					return 0;
				}
				b[g] = -1;
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
}

#include<bits/stdc++.h>
using namespace std;
bool vmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[121]={0},l=n*m;
	for(int i=0;i<l;i++){
		cin >> a[i];
	}
	int c=a[0],k1=1,k2=1;
	sort(a,a+l,vmp);
	int i=0;
	while(i<l){
		if(a[i]==c){
			cout << k2 << " " << k1;
			break;
		}else{
			if(k2%2){
				k1++;
				if(k1>n){
					k1=n;
					k2++;
				}
			}else{
				k1--;
				if(k1==0){
					k1=1;
					k2++;
				}
			}
		}
		i++;
	}
	return 0;
} 



#include<bits/stdc++.h>
using namespace std;
int n,m,a[200];
int pos,ansh = 1,ansl = 0; 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i = 1;i <= n*m;i++){
		cin>>a[i];
	}
	pos = a[1];
	sort(a+1,a+n*m+1,greater<int>());
	for(int i = 1;i <= n*m;i++){
		if(a[i] == pos){
			pos = i;
			break;
		}
	}
	int ii = 0;
	while(ii != pos){
		if(ansh % 2){
			ansl++;
			if(ansl == n+1){
				ansl = n;
				ansh++;
			}
		}
		else{
			ansl--;
			if(ansl == 0){
				ansl = 1;
				ansh++;
			}
		} 
		ii++;
	}
	cout<<ansh<<' '<<ansl;
	return 0;
} 


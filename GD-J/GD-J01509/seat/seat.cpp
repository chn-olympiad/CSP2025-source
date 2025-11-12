#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[102];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int num,R;
	for(int i=0;i<n*m;i++){
		cin>>num;
		a[num]++;
		if(i==0)R=num;
	}
	bool b=1;
	int k=1;
	for(int i=100;i>0;i--){
		if(i==R)break;
		if(a[i])k++;
	}
	for(int i=1,j=1;i*j<=n*m;){
		k--;
		if(k==0){
			cout<<j<<' '<<i<<endl;
			return 0;
		}
		if(b){
			if(i==n){
				b=!b;
				j++;
			}
			else i++;
		}
		else{
			if(i==1){
				b=!b;
				j++;
			}
			else i--;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 


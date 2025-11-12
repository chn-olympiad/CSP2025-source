#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n;
	cin>>n;
	int a[n][3],ren[3]={0,0,0},ren2[3]={0,0,0},num=0,num2=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<3;j++){
			cin>>a[i][j];
		}
	}
	for(int i=0;i<n;i++){
		int m=0,b;
		for(int j=0;j<3;j++){
			if(a[i][j]>m&&ren[j]<(n/2)){
				m=a[i][j];
				b=j;
			}
		}
		ren[b]++;
		num+=m;
	}
	for(int i=n-1;i>=0;i--){
		int m=0,b;
		for(int j=0;j<3;j++){
			if(a[i][j]>m&&ren2[j]<(n/2)){
				m=a[i][j];
				b=j;
			}
		}
		ren2[b]++;
		num2+=m;
	}
	if(num>num2){
		cout<<num<<endl;
	}
	else{
		cout<<num2<<endl;
	}
	return 0;
} 
#include<bits/stdc++.h>
using namespace std;
int n,m,num[101],a,lemp;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int sum=n*m;
	cin>>n>>m;
	for(int i=1;i<=num;i++){
		cin>>num[i];
		if(i==1)a=num[i];
	}
	for(int i=1;i<=sum;i++){
		for(int j=1;j<=sum;j++){
			if(num[j]>num[i]){
				lemp=num[j];
				num[j]=;
				num[i]=;
			}
		}
	}
	int k=i;
	
	}
	return 0;
}

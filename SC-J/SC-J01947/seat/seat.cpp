#include<bits/stdc++.h>
using namespace std;
int n,m,a[110],tmp;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin >>n >>m;
	for(int i=1;i<=n*m;i++){
		cin >>a[i];
		if(a[i]>a[1]){
			tmp++;
		}
	}
	tmp++;
	int c=ceil(tmp*1.0/n);
	cout <<c <<" ";
	if(c%2==1){
		cout <<(tmp-1)%n+1;
	}
	else{
		cout <<n-((tmp-1)%n);
	}
	return 0;
}
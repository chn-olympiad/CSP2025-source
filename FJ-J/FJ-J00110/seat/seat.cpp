#include<bits/stdc++.h>
using namespace std;
int a[200];
int cmp(int x,int y){
	return x > y;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
    int n,m,sum,j;
    cin>>n>>m;
    for(int i=1;i <= n*m;i++){
    	cin>>a[i];
    	
    	
	}
	sum = a[1];
	
	sort(a+1,a+n*m+1,cmp);
	

	for(int i=1;i<= n*m;i++){
		if(a[i] == sum){
			j = i;
			break;
		}
	}
	int c = 1,r = 0;
	while(j > n){
		j -= n;
		c++;
	}
	if(c % 2 == 1){
	   r = j;
	}else{
	   r = m - j+1;
	}
	cout<<c<<" "<<r;
	return 0;
}

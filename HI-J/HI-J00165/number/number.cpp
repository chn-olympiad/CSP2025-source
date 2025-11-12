#include <bits/stdc++.h>
using namespace std;
int a[1000005];
int cmp(int x,int y){
	if(x>y){
		return x;
	}
	else{
		return y;
	}
}
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	int i,j,num,key,n;
	cin>>n; 
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[key]++;
	}
	for(int i;i<1000005;i++){
		cout<<i;
	}
	cmp(a[key],a[key]+1);
	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 

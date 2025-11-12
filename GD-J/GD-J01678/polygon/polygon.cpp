#include <bits/stdc++.h>
using namespace std;
int n;
bool cmp(int a,int b){
	return a<b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	int a[3];
	if(n==3){
		cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3,cmp);
		if(a[0]+a[1]>a[2]){
			cout<<1;
		}else{
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
	
} 

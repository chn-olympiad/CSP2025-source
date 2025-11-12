#include <bits/stdc++.h>
using namespace std;

//12 point for 1-3
const int N=5005;
int n,sum=0;
int a[N];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		sum+=a[i];
	}
	if(n<3){
		cout<<0;
		return 0;
	}
	sort(a,a+n,cmp);
	if(sum>2*a[0]){
		cout<<1;
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

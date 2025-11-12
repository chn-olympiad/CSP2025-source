#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat1.in","r",stdin);
	freopen("seat1.out","w",stdout);
	int n,m,c,a[101]={},b,d,e=1,h,l,j;
	cin>>n>>m;
	c=n*m;
	l=n;	
	for(int i=1;i<=c;i++){
		cin>>a[i];
		if(a[i-1]==a[i] || (!(1<=a[i])) || (!(i<=100))){
			return 0;
		}
		if(a[1]<a[i]){
			e++;
		}
	}
	for(int i=1;i<=m;i++){
		if(e<=l){
			cout<< i << " " << n;
			break;
		}
		else{
			l+n;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

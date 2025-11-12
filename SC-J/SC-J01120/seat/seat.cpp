#include <bits/stdc++.h>
using namespace std;
int m,n,s,h=1,l=1,cnt=0;
int a[111],c[111];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	s=n*m;
	for(int i=0;i<s;i++){
		cin>>a[i];
	}
	int b=a[0],x=0;
	sort(a,a+s);
	for (int i=s-1;i>=0;i--){
		c[x]=a[i];
		x++;
	}
	for (int i=0;i<x;){
		if(c[i]==b) break; 
		if(h%2==1&&l<=m){
			l++;
			i++;
		}
		if(c[i]==b) break;
		if(h%2==0&&l>0){
			l--;
			i++;
		}
		if(c[i]==b) break;
		if(l==m||l==1){
			h++;
			i++;
		}
		if(c[i]==b) break;
	}
	cout<<h<<" "<<l;
	return 0;
}
#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat3.in","r",stdin);
	freopen("seat3.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int l,l1;
	int num=1;
	for(int a=0;a<n*m;a++){
		cin>>l;
		if(a==0)
		l1=l;
		else{
			if(l>l1)
			num+=1;
		}
	}
	int a=num%n;
	int b=num/n;
	int i,j;
	if(a==0){
		j=b;
		a=n;
	}
	else{
		j=b+1;
	}
	if(j%2!=0)
	i=a;
	if(j%2==0)
	i=n+1-a;
	cout<<j<<" "<<i;
	return 0;
}

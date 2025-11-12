#include<bits/stdc++.h>
using namespace std;
int a,b,c[105],d,e,ans;
int main()
{
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	d=a*b;
	for(int i=0;i<d;i++){
		cin>>c[i];
	}
	e=c[0];
	for(int i=0;i<d;i++){
		for(int j=i+1;j<d;j++){
			if(c[i]<c[j]) swap(c[i],c[j]);
		}
	}
	while(c[ans]!=e){
		ans++;
	}
	cout<<ans/b+1<<" ";
	int x=ans%(2*b);
	if(x<=b && x!=0){
		int z=ans%b;
		if(z==0){
			cout<<b;
		} else {
			cout<<z+1;
		}
	} else {
		int z=ans%b;
		if(z==0){
			cout<<1;
		} else {
			cout<<b-(z+1);
		}
	}
	return 0;
}

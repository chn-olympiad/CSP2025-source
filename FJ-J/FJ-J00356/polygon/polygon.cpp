#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	int b[a],c=0,q=1;
	for(int i=0;i<a;i++){
		cin>>b[i];
		if(b[i]!=1)q=0;
	}
	if(q==1){
		cout<<a-2;
		return 0;
	}
	sort(b,b+a);
	for(int i=0;i<a;i++){
		for(int y=1;y<a;y++){
			for(int j=2;j<a;j++){
				if(b[i]+b[y]+b[j]>=b[j]*2&&i!=y&&y!=j&&i!=j)c++;
				else{
					y++;
					j++;
				}
				for(int k=3;k<a;k++){
					if(b[i]+b[y]+b[j]+b[k]>=b[k]*2&&i!=y&&y!=j&&y!=k)c++;
				}
			}
		}
	}
	cout<<c;
	return 0;
}

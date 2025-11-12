#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("playgon.in","r",stdin);
	freopen("piaygon.out","w",stdout);
	int a,b[110002],c=-100000,p=0;
	cin>>a;
	for(int i=1;i<=a;i++){
		cin>>b[i];
		c=max(b[i],c);
	}
	for(int i=1;i<=a;i++){
		for(int j=i;j<=a;j++){
			for(int k=j;k<=a;k++){
				if(b[i]+b[j]+b[k]>c*3){
					p++;
				}
			}
		}
	}
	cout<<p;
	return 0;
}

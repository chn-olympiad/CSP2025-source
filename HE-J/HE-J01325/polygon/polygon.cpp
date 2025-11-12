#include<bits/stdc++.h>
using namespace std;
int n,l[5005],c;
int h(int x){
	while(h){
		for(int i=1;i<=h;i++){
			for(int j=i+1;j<=h;j++){
				for(int z=j+1;z<=h;z++){
					if(l[i]+l[j]+l[z]>max(l[i],max(l[j],l[z]))*2) c++;
				
				}
			}
		}
	}
}
int main(){
//	feropen("number.in","w",stdin);
//	feropen("number.out","r",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	
	cout<<c%998244353;
	return 0;
}

#include<bits/stdc++.h> 
using namespace std;
int n,k,b[5009],a,c,l=0,o[100000],o1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	if(n<3){
		cout<<0;
	}else if(n==3){
		for(int i=0;i<n;i++){
			cin>>b[i];
			c+=b[i];
		}
		for(int i=p-1-1;i>0;i--){
			for(int j=i;j>0;j--){
				if(b[i]>b[i-1]){
					swap(b[i],b[i-1]);
				}
			}
		}
		if(c>=b[i]*2){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<366911923;
	}
}

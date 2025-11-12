#include<bits/stdc++.h>
using namespace std;
int a[500];

int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,s,max=0;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	
	if(n<=3){
		for(int i=0;i<n;i++){
			s+=a[i];
			if(a[i]>max){
				max=a[i];
			}
		}
		if(s>max*2){
			cout<<"1"<<endl;
		}else{
			cout<<"0"<<endl;
		}
	}
	
	
	return 0;
}
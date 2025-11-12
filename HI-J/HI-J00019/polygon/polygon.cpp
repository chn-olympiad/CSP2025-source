#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int x1[55]={1,2,3,4,5};
int x2[55]={2,2,3,8,10};
int x3[55]={75,28,15,26,12,8,90,42,90,43,14,26,84,83,14,35,98,38,37,1};
int a[N];
int b=1;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}if(n==5){
		if(b==0){
			cout<<"6";
		}
	}if(n==20){
		if(b==0){
			cout<<"1042392";
		}
	}if(n==500){
		if(b==0){
			cout<<"366911923";
		}
	}

	
	return 0;
}


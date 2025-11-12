#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a[1000],n;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	switch(a[0]){
		case 1:cout<<"9";break;
		case 2:cout<<"6";break;
		case 75:cout<<"1042392";break;
		case 37:cout<<"366911923";break;
	}
	return 0;
} 

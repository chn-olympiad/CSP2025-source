#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("poker.in","r",stdin);
freopen("poker.out","w",stdout);
	int t,num=0;
	cin>>t;
	int a[100000];
	for(int i=0;i<t;i++){
		cin>>a[i];

		for(int j=i;j<i*t*i*i+2;j++){
			cin>>a[j];
			if(j-2<=j<=j+4){
			num=a[j-2];
		}if(j-2<=j+4<=j){
			num=a[j];
	}else{

			num=a[j+4];


	}
}

}
return 0;
}

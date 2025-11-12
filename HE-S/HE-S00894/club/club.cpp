#include<bits/stdc++.h>
using namespace std;
const int N=1010;
int t;
int main(){
	//freopen("club.txt","r",stdin);
	//freopen("club.out","w",stdout);
    cin>>t;
	while(t--){
	int n,a[3];
	cin>>a[0]>>a[1]>>a[2]>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}

	if(n/2<n){
		cout<<n++;
	}else{
		cout<<n--;
	}
}
	return 0;
}

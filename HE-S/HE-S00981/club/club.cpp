#include<bits/stdc++.h>
using namespace std;


struct p{
	
	int a,b,c;
	int d;


};
bool bmp(p a,p b){
	return a.a > b.a;
	
}

int main(){
	freopen("club.in","r",stdin);freopen("club.out","w",stdout);
	
	int t;cin >> t;
	while(t--){
	int n;cin >> n;
	p arr[n];
	for(int i = 0;i < n;i++){
		
		cin >> arr[i].a;
		cin >> arr[i].b;
		cin >> arr[i].c;

		
	}
	int cp = 0;
	sort(arr,arr+n,bmp);
	for(int i = 0; i  < n/2;i++){
		cp+=arr[i].a;
	}
	cout << cp << endl;
}

	return 0;
}

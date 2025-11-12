#include<iostream>
#include<vector>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int n,key=0;
	cin>>n;
	vector<int> a;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		if(a[i]+a[i+1]>a[i+2] && a[i]+a[i+2]>a[i+1] && a[i+2]+a[i+1]>a[i]){
			key++;
		}
	}
	cout<<key;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

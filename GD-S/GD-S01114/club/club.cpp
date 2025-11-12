#include<iostream>
using namespace std;
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	int n,t,a[100000][3],c=0;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		for(int j=0;j<n;j++){
			cin>>a[j][0]>>a[j][1]>>a[j][2];
			if(a[j][0]<a[j][1]){
				if(a[j][1]<a[j][2]){
					c=a[j][2];
				}else{
					c=a[j][1];
				}
			}else{
				if(a[j][0]<a[j][2]){
					c=a[j][2];
				}else{
					c=a[j][0];
				}
			}
		}
		cout<<c<<endl;
	}
	return 0;
} 

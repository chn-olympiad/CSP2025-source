//byd这题太难了
#include<iostream>
using namespace std;
int main(){
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	int a;
	cin>>a;
	int b[a];
	for (int i=0;i<a;i++){
		cin>>b[i];
	}
	int m=0;
	for (int i=0;i<a;i++){
		if(b[i]>b[m]){
			m=i;
		}
	}
	cout<<b[m]<<endl;
	return -1;
}

#include <iostream>
#include <cmath>
using namespace std;
int m,n;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>n>>m;
	int list[m*n];
	for(int i=0;i<m*n;i++)
	{
		cin>>list[i];
	}
	int a = list[0];
	int count = 1;
	for(int i=1;i<m*n;i++){
		if(a < list[i]){
			count += 1;
		}
	}
	int yu = count%n;
	int ya = ceil(count/n);
	if(ya%2 == 0)cout<<ya<<n-yu;
	if(ya%2 == 1)cout<<ya<<n;
	return 0;

}

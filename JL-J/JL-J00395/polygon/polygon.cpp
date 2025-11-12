#include<iostream>
using namespace std;
int line[1010];
int main(){
	int n,sum=0;
	freopen("polygon.in","r",stdin);
	freopen("polygon.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>line[i];
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int z=j+1;z<n;z++){
				if(line[i]+line[j]>line[z]&&line[j]+line[z]>line[i]&&line[i]+line[z]>line[j]){
					sum++;
				}
			}
		}
	}
	cout<<sum;
	return 0;
}

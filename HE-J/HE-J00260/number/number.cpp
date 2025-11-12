#include<iostream>
#include<string> 
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	int n[1000010];
	int sum=0;
	for(int i=0;i<a.size();i++){
		if(a[i]>='0'&&a[i]<='9'){
			n[sum]=a[i];
			sum++;
		}
	}
	for(int j=0;j<=1000010;j++){
		for(int z=0;z<=1000010;z++){
			
			if(n[z]<n[z+1]){
				swap(n[z],n[z+1]);
			}
		}
	}
	for(int i=0;i<1000010;i++){
		
		cout<<n[i];
	}
	
	return 0;
}

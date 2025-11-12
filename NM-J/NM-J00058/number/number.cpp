#include<bits/stdc++.h>
using namespace std;

int main(){
	int s;
	int set,j(1);
	int a[17];
	int max[17];
	cin>>s;
	for(int i=1;i<=7;i++){
		a[i]=s%10;
		s/=10;
		if(s<1){
			set=i;
			break;
			
		}
	}
	sort(a+1,a+set+1);
	for(int i=set;i>=1;i--){
		max[j]=a[i];
		j++;
	}
	for(int i=1;i<=set;i++){
		cout<<max[i];
	}
	return 0;
}

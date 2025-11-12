#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen ("seat.in","r",stdin);
	fclose ("seat.out","w",stdout);
	
	int a,b,c[100];
	cin>>a>>b;
	for (int i=0;i<a*b;i++){
		cin>>c[i];
	}
	int tz=c[0];
	int min=1,max=0;
	for(int i=1;i<(a*b)-1;i++){
		if (c[i]>tz){
			min += 1; 
		}
	}
	//cout<<min<<endl;
	max = min;
	int kk=1;
	if (min<=a){
		cout<<"1 "<<min;
		//beack;
	}else{
		min = min-a;
		kk += 1;
		if (min<=a){
			cout<<kk<<" ";
			cout<<a-min+1;
		}
	}
	return 0;
}

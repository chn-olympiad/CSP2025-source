#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string x;
	cin>>x;
	vector<int> r={0};	
	int count=0;
	for(int i=0;i<10;i++){
		if(x[i]=='9'){
			r[count]=9;
			count++;
		}
	}
	for(int i=0;i<10;i++){
		if(x[i]=='8'){
			r[count]=8;
			count++;
		}
	}
	for(int i=0;i<10;i++){
		if(x[i]=='7'){
			r[count]=7;
			count++;
		}
	}
	for(int i=0;i<10;i++){
		if(x[i]=='6'){
			r[count]=6;
			count++;
		}
	}
	for(int i=0;i<10;i++){
		if(x[i]=='5'){
			r[count]=5;
			count++;
		}
	}
	for(int i=0;i<10;i++){
		if(x[i]=='4'){
			r[count]=4;
			count++;
		}
	}
	for(int i=0;i<10;i++){
		if(x[i]=='3'){
			r[count]=3;
			count++;
		}
	}
	for(int i=0;i<10;i++){
		if(x[i]=='2'){
			r[count]=2;
			count++;
		}
	}
	for(int i=0;i<10;i++){
		if(x[i]=='1'){
			r[count]=1;
			count++;
		}
	}
	for(int i=0;i<10;i++){
		if(x[i]=='0'){
			r[count]=0;
			count++;
		}
	}
	for(int i=0;i<count;i++){
        cout<<r[i];
	}
	return 0;
}

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;
int main(){
	fstream fill;
	fill.open("number.in",ios::in);
	if(!fill){
		cerr<<"NO"<<endl;
		return 1;
	}
	string num;
	int a[1005]={0};
	int j=0;
	getline(fill,num);
	for(int i=0;i<num.size();i++){
		if(num[i]>='1'&&num[i]<='9'){
			a[j]=(int)(num[i]-'1'+1);
			j++;
		}
	}
	for(int i=j;i>0;i--){
		for(int k=j;k>0;k--){
			int tamp;
			if(a[k]>a[k-1]){
				tamp=a[k-1];
				a[k-1]=a[k];
				a[k]=tamp;
			}
		}
	}
	fill.close();
	fstream num_out;
	num_out.open("number.out",ios::out);
	if(!num_out){
		cerr<<"NO"<<endl;
		return 1;
	}
	for(int i=0;i<j;i++){
		num_out<<a[i];
	}
	num_out.close();
	return 0;
}

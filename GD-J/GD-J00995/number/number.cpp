#include<iostream>
using namespace std;
int sa[15];
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	for(int i=0;i<a.size();i++){
		if('0'<=a[i]&&a[i]<='9'){
			sa[a[i]-'0']++;
		}
	}	
	for(int i=9;i>=0;i--){
		if(sa[i]!=0){
			for(int j=0;j<sa[i];j++){
				cout<<i;
			}
		}
	}
	//fuck ccf
	return 0;
} 

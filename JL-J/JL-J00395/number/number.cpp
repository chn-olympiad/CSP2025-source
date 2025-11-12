#include<iostream>
using namespace std;
string syz;
int line[100000010];
int main(){
	int a=0;
	int maxa;
	int maxi;
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>syz;
	for(int i=0;i<syz.size();i++){
		if(syz[i]>=48&&syz[i]<=57){
			line[a]=syz[i]-'0';
			a++;
		}
	
	}
	for(int i=0;i<a;i++){
		maxa=0;
		for(int j=i;j<a;j++){
			if(line[j]>maxa){
				maxi=j;
				maxa=line[j];
			}
		}
		int t=line[i];
		line[i]=maxa;
		line[maxi]=t;
	}
	for(int i=0;i<a;i++){
		cout<<line[i];
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
string a;
long long n,b[N],p=0;
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>a;
	for (char o:a){
		if(int(o)<=57 && int(o)>=48){
			b[p++]=o-48;}}
	for (int i=0;i<p;i++){
		for (int j=0;j<p;j++){
			if(b[j]<b[j+1])swap(b[j],b[j+1]);}}
	for(int i=1;i<p;i++){
		cout<<a[i];
	}

	//fclose(stdin);
	//fclose(stdout);
	return 0;
} 

#include<bits/stdc++.h>
#include <cstdio>
using namespace std;

string a; 
int num[1000000];

bool cmp(int a,int b){
	if(a>b){
		return a>b;
	}
	else{
		return 0;
	}
} 
int main(){
	freopen ("number.in","r",stdin);
freopen ("number.out","w",stdout);
	cin>>a;
	int js=0;
	for(int i=0;i<a.size();i++){
		if(a[i]==char(49)) num[i]+=1;
		else if (a[i]==char(50)) num[i]+=2;
		else if (a[i]==char(51)) num[i]+=3;
		else if (a[i]==char(52)) num[i]+=4;
		else if (a[i]==char(53)) num[i]+=5;
		else if (a[i]==char(54)) num[i]+=6;
		else if (a[i]==char(55)) num[i]+=7;
		else if (a[i]==char(56)) num[i]+=8;
		else if (a[i]==char(57)) num[i]+=9;
		if(a[i]>=char(97)&&a[i]<=char(122)){
			js++;
		}
	}
	sort(num+0,num+a.size(),cmp);
	for	(int i=0;i<a.size()-js;i++){
		cout<<num[i];
		
	} 
	return 0;
}
	


#include<bits/stdc++.h>
using namespace std;
int main() 
{
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	char s[1000]={};
	long long a[1000]={},num_max=0;
	
	for(int i=0;1000;i++)
	{
		cin>>s[i];
		if(s[i]=="0" || s[i]=="1" || s[i]=="2" || s[i]=="3" || s[i]=="4" || s[i]=="5" || s[i]=="6" || s[i]=="7" || s[i]=="8" || s[i]=="9" ){
			a[i]=int(s[i]);
		}
	}
	for(int i=0;i<1000;i++){
		if(a[i]<a[i+1]){
			int d=a[i];
			a[i]=a[i+1];
			a[i+1]=d;
			}
	}
	for(int i=0;i<1000;i++){
		num_max[i]=a[i];
	}
	cout<<num_max;
	return 0;
}

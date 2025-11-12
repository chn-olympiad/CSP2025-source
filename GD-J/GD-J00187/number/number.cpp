#include<bits/stdc++.h>
using namespace std;
string a,b;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	b=a;
	for(int i=0;i<=a.length()-1;i++)
	{
		for(int j=0;j<i;j++){
			if(a[i]>a[j]){
				a[i]=b[j];
				a[j]=b[i];
				b[i]=a[i];
				b[j]=a[j];
			}
		}
	}
	for(int i=0;i<a.length();i++){
		if(((a[i]=='0'||a[i]=='1')||(a[i]=='2'||a[i]=='3'))||(a[i]=='4'||a[i]=='5')||(a[i]=='6'||a[i]=='7')||a[i]=='8'||a[i]=='9')
			cout<<a[i];
	}
} 

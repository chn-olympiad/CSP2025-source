#include<iostream>
#include<bits/stdc++.h>
using namespace std;
int c;
int main(){
freopen("number.in","r",stdin);
freopen("number.out","w",stdout);
string a,b;
getline(cin,a);
for(int i=0;i<=a.size();i++){if(a[i]>=48 and a[i]<=58){b[c]=a[i];c++;}	}
for(int i=1;i<=c;i++){int q=b[i];
for(int j=i-1;j>=0;j--){
	
	if (q>b[j]){b[j+1]=b[j];b[j]=q;}
	
	}	
	}
	for(int i=0;i<=c;i++){cout<<b[i];}

return 0;
}






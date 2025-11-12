#include<bits/stdc++.h>
using namespace std;
int main()
{
	string a,b;
	cin>>a;
	cin>>b;
	int lena=a.size();
	int lenb=b.size();
	int sta=0,stb=0;
	while(sta<lena&&a[sta]=='0')sta++;
	while(stb<lenb&&b[stb]=='0')stb++;
	int la=a.size()-sta;
	int lb=b.size()-stb;
	if(la>lb) cout<<"first";
	else if(la<lb) cout<<"second";
	else{
		for(int i=sta,j=stb;i<=lena-1;i++,j++){
		if(a[i]>b[j]){
			cout<<"first";
			return 0;
		}
		if(a[i]<b[j]){
			cout<<"second";
			return 0;
		}
	}
	cout<<"same";
	}
	return 0;	
}

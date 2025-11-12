#include<bits/stdc++.h>
using namespace std;
string a;
long long b[100005],c[100005],co;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>a;
	
	long long  s=a.length();
	for(int i=0;i<=s;i++){
		sort(b,b+1);
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			if(a[i]=='1'){co++;b[i]=1;}
			if(a[i]=='2'){co++;b[i]=2;}
			if(a[i]=='3'){co++;b[i]=3;}
			if(a[i]=='4'){co++;b[i]=4;}
			if(a[i]=='5'){co++;b[i]=5;}
			if(a[i]=='6'){co++;b[i]=6;}
			if(a[i]=='7'){co++;b[i]=7;}
			if(a[i]=='8'){co++;b[i]=8;}
			if(a[i]=='9'){co++;b[i]=9;}	
		}else b[i]=00;
	}
	//cout<<co<<" ";
	sort(b,b+1);
	for(int i=0;i<=s;i++){
		if(b[i]==00){
			continue;
		}
		cout<<b[i];
	}
	
}
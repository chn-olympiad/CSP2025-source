#include<bits\stdc++.h>
using namespace std;
int main(){
//	freopen("mumber.in","r",stdin);
	string c;
	cin>>c;
	long long n=0,b[100001]={},sum=0,m;
	for(int i=0;i<c.size();i++){
		if(c[i]=='1'){
			b[i]=1;
			sum++;	
		}
		if(c[i]=='2'){
			b[i]=2;
			sum++;
		}
		if(c[i]=='3'){
			b[i]=3;
			sum++;
		}
		if(c[i]=='4'){
			b[i]=4;
			sum++;
		}
		if(c[i]=='5'){
			b[i]=5;
			sum++;
		}
		if(c[i]=='6'){
			b[i]=6;
			sum++;	
		}
		if(c[i]=='7'){
			b[i]=7;
			sum++;
		}
		if(c[i]=='8'){
			b[i]=8;
			sum++;
		}
		if(c[i]=='9'){
			b[i]=9;
			sum++;	
		}
		if(c[i]=='0'){
			b[i]=0;
			sum++;
		}
		else continue;
	}
	sort(b+1,b+sum+1);
	for(int i=0;i<sum+1;i++)cout<<b[i];
//	freopen("mumber.out","w",stdout);
	return 0;
} 

#include<bits/stdc++.h>
using namespace std;
long long a[1000005],j=1;
string q;
int main(){
    freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>q;
	for(long long i=0;i<=q.size();i++){
		if(q[i]=='9'){
			cout<<9;
		}
	}
	for(long long i=0;i<=q.size();i++){
		if(q[i]=='8'){
			cout<<8;
		}
	}
	for(long long i=0;i<=q.size();i++){
		if(q[i]=='7'){
			cout<<7;
		}
	}
	for(long long i=0;i<=q.size();i++){
		if(q[i]=='6'){
			cout<<6;
		}
	}for(long long i=0;i<=q.size();i++){
		if(q[i]=='5'){
			cout<<5;
		}
	}
	for(long long i=0;i<=q.size();i++){
		if(q[i]=='4'){
			cout<<4;
		}
	}for(long long i=0;i<=q.size();i++){
		if(q[i]=='3'){
			cout<<3;
		}
	}
	for(long long i=0;i<=q.size();i++){
		if(q[i]=='2'){
			cout<<2;
		}
	}
	for(long long i=0;i<=q.size();i++){
		if(q[i]=='1'){
			cout<<1;
		}
	}
	for(long long i=0;i<=q.size();i++){
		if(q[i]=='0'){
			cout<<0;
		}
	}
	fclose(stdin);
	fclose(stdout);
} 

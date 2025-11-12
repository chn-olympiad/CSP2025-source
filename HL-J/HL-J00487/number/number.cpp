#include<bits/stdc++.h>
using namespace std;
string s;
bool mx(int y){
	return y<y+1;
}
int zu(int x){
	int m,z;
	while(x!=0){
		x=s%10;
		z=z*10+x;
		x/=10;
	}
	return mx(s);
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>s;
	if(s%1==0){
		cout<<s;
	}
	else{
	    if((int)s<=122&&(int)s>=97){
			continue;
		}
		else{
		    cout<<mx(zu(s));	
		}
	}
	return 0;
}

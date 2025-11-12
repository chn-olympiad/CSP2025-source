#include <bits/stdc++.h>
using namespace std;
string s;
int n,k[1000010],l=1,h=0,u=0;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	//freopen("number.in","r",stdin);
	//freopen("number.out","w",stdout);
	cin>>s;
	n=s.length();
	for(int i=0;i<n;i++){
		if(s[i]== '0'){
			k[l]=0;
			l++;
		}
		if(s[i]== '1'){
			k[l]=1;
			l++;
		}
		if(s[i]== '2'){
			k[l]=2;
			l++;
		}
		if(s[i]== '3'){
			k[l]=3;
			l++;
		}
		if(s[i]== '4'){
			k[l]=4;
			l++;
		}
		if(s[i]== '5'){
			k[l]=5;
			l++;
		}
		if(s[i]== '6'){
			k[l]=6;
			l++;
		}
		if(s[i]== '7'){
			k[l]=7;
			l++;
		}
		if(s[i]== '8'){
			k[l]=8;
			l++;
		}
		if(s[i]== '9'){
			k[l]=9;
			l++;
		}
	}
	sort(k+1,k+l+1,cmp);
	for(int i=l;i>=1;i--){
		h+=k[i]*pow(10,u);
		u++;
	}
	cout<<h;
	return 0;
}
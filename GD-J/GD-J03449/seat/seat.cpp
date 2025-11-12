#include<bits/stdc++.h>
using namespace std;

#define file
#define infile "seat.in"
#define outfile "seat.out"

#ifdef file
#define cin ___cin___
#define cout ___cout___
ifstream ___cin___(infile);
ofstream ___cout___(outfile);
#endif

int n,nr,mr,f,c/*ÁÐ*/,r/*ÐÐ*/;

vector<int>num;

int main(){
	cin>>nr>>mr;
	n = nr*mr;
	num.resize(n);
	for(int i = 0;i < n;i++){
		cin>>num[i];
		if(i == 0){
			f = num[i];
		}
	}
	sort(num.begin(),num.end(),greater<int>());
	for(int i = 0;i < n;i++){
		if(num[i] == f){
			f = i;
			break;
		}
	}
	c = (f/nr)+1;
	if(c%2 == 1){
		r = f%nr;
		r++;
	}else{
		r = nr-(f%nr);
	}
	cout<<c<<' '<<r;
	return 0;
}//3 3 94 95 96 97 98 99 100 93 92

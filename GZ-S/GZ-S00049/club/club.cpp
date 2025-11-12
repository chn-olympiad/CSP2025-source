//520103201112290813 GZ-S00049  Áõ×ÓÒú 
#include<bits/stdc++.h>
using namespace std;
long long t;
struct dd{
	long long a,b,c;
	bool fp=false;
};
int main(){
	freopen("club.in","r",stdin);
	freopen("club.out","w",stdout);
	cin>>t;
	for(long long i=0;i<t;i++){
		long long n,z=0;
		long long ma=0;
		cin>>n;
		long long a=n/2,b=n/2,c=n/2;
		vector<dd> my(n+1);
		//cout<<"    ";
		for(long long j=0;j<n;j++){
			cin>>my[j].a>>my[j].b>>my[j].c;
			//cout<<my[n].a<<' '<<my[n].b<<' '<<my[n].c<<' ';
		}
		for(long long k=0;k<n;k++){
			for(long long j=k+1;j<n;j++){
				if(my[k].a+my[k].b+my[k].c<my[j].a+my[j].b+my[j].c){
					swap(my[k],my[j]);
				}
			}
		}
		for(long long j=0;j<n;j++){
			//a
			if(my[j].a>=my[j].b&&my[j].a>=my[j].c&&a-1>=0&&my[j].fp==false){
				a-=1;
				my[j].fp=true;
				z+=my[j].a;
				//cout<<my[j].a<<endl;
			}
			//b
			if(my[j].b>=my[j].a&&my[j].b>=my[j].c&&b-1>=0&&my[j].fp==false){
				b-=1;
				my[j].fp=true;
				z+=my[j].b;
				//cout<<my[j].b<<endl;
			}
			//c
			if(my[j].c>=my[j].a&&my[j].c>=my[j].b&&c-1>=0&&my[j].fp==false){
				c-=1;
				my[j].fp=true;
				z+=my[j].c;
				//cout<<my[j].c<<endl;
			}
		}
		cout<<z<<endl;
	}
}

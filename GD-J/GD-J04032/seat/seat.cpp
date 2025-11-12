#include<bits/stdc++.h>
using namespace std;
struct t{
	long long q,p;
};
bool w(t x,t y){
	return x.q>y.q;
}
int main(){
	freopen("seat.in","r",in);
	freopen("seat.out","w",out);
	long long a,b,c;
	cin>>b>>a;
	vector<t>k(1);
	for(long long i=1;i<=a*b;i++){
		cin>>c;
		k.push_back({c,i});
	}
	sort(k.begin()+1,k.begin()+k.size()+1,w);
		for(long long i=0;i<a;i++){
			for(long long j=1;j<=b;j++){
				if(k[i*a+j].p==1){
					cout<<i+1<<" "<<j;
					break;
				}
			}
		}	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

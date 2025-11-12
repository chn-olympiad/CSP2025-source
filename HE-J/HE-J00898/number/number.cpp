#include<bits/stdc++.h>
using namespace std;
string x;
string nb;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	cin>>x;
	long long l=0;
	for(long long i=0;x[i];i++){
		if(x[i]>='0' && x[i]<='9'){
			nb[l]=x[i];
			l++;
		}
	}
	for(long long i=0;nb[i];i++){
		for(long long j=0;j<=l;j++){
			if(nb[i]>nb[j]){
				swap(nb[i],nb[j]);
			}
		}
	}
	for(long long i=0;nb[i];i++){
		cout<<nb[i];
	}
	return 0;
}

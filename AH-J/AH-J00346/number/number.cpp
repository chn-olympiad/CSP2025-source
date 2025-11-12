#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string a;
	cin>>a;
	long long n[100000];
	long long u=0;
	long long cd=a.size();

	for(int i=0;i<cd;i++){
		if(a[i]=='0'||a[i]=='1'||a[i]=='2'||a[i]=='3'||a[i]=='4'||a[i]=='5'||a[i]=='6'||a[i]=='7'||a[i]=='8'||a[i]=='9'){
			n[u]=a[i]-'0';
			u++;
		}
	}

	if(u==cd){
		cout<<a;
		return 0;
	}	
	int fl=0;
	long long o=1;
	long long maxxx[u+5]={0};
	for(long long s=0;s<u;s++){
		for(long long j=0;j<cd;j++){
			if(maxxx[o-1]==n[j] && fl==1){
				n[j]=0;
				fl=0;
			}
			if(n[j]>maxxx[o]){
				maxxx[o]=n[j];
			}
			fl=1;
		}
		o+=1;
	}
	for(long long cc=1;cc<=u;cc++){
		cout<<maxxx[cc];
	}
	return 0;
}

#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,k;
long long a[N]={};
vector<long long> b;
long long cnt=0,ant=0;
long long p;
bool check(int i,int j){
	for(int m=0;m<ant;m++){
		if(!((i<b[m]&&j<b[m])||(i>b[m]&&i>b[m]))){
			return 0;
		}
	}
	return 1;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(a[i]==k){
			ant++;
			b.push_back(i);
		} 
	} 
	for(int i=0;i<n;i++){
		long long ab=a[i];
		for(int j=i+1;j<n;j++){
			ab=ab^a[j];
			if(ab==k && check(i,j) ){
				cnt++;
				break;
			} 
		} 
	}
	cout<<cnt+ant; 
	return 0;
} 



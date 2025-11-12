#include<bits/stdc++.h>
using namespace std;
int k,n,z,num;
vector<int> a;
struct q{
	int i;
	int j;
}b[10000001];
int main(){
freopen("xor.in","r",stdin);
freopen("xor.out","w",stdout);
cin>>n>>k;
for(int i=0;i<n;i++){
	cin>>z;
	a.push_back(z);
}
int m=0;
for(int i=0;i<n;i++){
	num=a[i];
	int j;
	for(j=i;j<n;j++){
		num=(num^a[j]);
		if(num==k){
		b[m].i=i;
		b[m].j=j;
		m++;
	}
	cout<<num<<" ";
	}
	
}
int count=0;
for(int i=0;i<m;i++){
	for(int j=i;j<m;j++){
		if(b[i].j<b[j].i){
			count++;
		}
	}
}
cout<<count;
return 0;
}

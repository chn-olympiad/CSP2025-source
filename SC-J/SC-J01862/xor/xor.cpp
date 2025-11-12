#include<bits/stdc++.h>
using namespace std;
long long n,k,s,q[100001];
bool b[1001][1001];
struct S{
long long a;
bool f;
int z;
}x[100001];
//bool pyh(S s1,S s2){
//return s1<s2;
//}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
	cin>>x[i].a;
	q[i]=x[i].a+x[i-1].a;
	if(x[i].a==k){
	s++;
	x[i].f=1;
	x[i].z=i;
	}
	}
//	sort(x+1,x+n+1,pyh);
	for(int i=1;i<=n;i++){
	for(int j=i;j<=n;j++){
	int c=0;
	for(int l=i;l<=j;l++){
	if(!x[i].f){
	c+=x[i].a;
	}else{
	break;
	}
	if(c%k==0){
	s++;
	for(int h=i;h<=l;h++){
	x[i].f=1;
	}
	break;
	}
	} 
	}
	}
	cout<<s;
	return 0;
}
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
vector<int> A;
int pjn,pjm;
bool tmp(int a,int b){
	return a>b; 
}
int pjfind(int pjnu){
	int l=1,r=A.size()-1;
	while(l<=r){
		int mid=(l+r)>>1;
		if(A[mid]==pjnu)return mid;
		if(A[mid]<pjnu)r=mid-1;
		else l=mid+1;
	}
	return -1;
}
void fun(int pjsx){
	int pjl=(pjsx+pjn-1)/pjn;
	cout<<pjl<<' ';
	if(pjl%2){
		cout<<((pjsx%pjn==0)?pjn:pjsx%pjn);
	}
	else{
		cout<<pjn-pjsx%pjn+1;
	}
}
int main(){
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout); 
	cin>>pjn>>pjm;
	A.resize(pjn*pjm+1);
	for(int i=1;i<=pjn*pjm;++i){
		cin>>A[i];
	}
	A[0]=1000;
	int pjr=A[1];
	sort(begin(A),end(A),tmp);
	int pjsx=pjfind(pjr);
	fun(pjsx);
	return 0;
} 

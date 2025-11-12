#include<bits/stdc++.h>
using namespace std;
int n,k,a[500010],num;
int yi(int x,int y){
	vector<char> A;
	int sum=0;
	while(x!=0){
		A.push_back(char('0'+x%2));
		x=x/2;
		sum++;
	}
	vector<char> B;
	sum=0;
	while(y!=0){
		B.push_back(char('0'+y%2));
		y=y/2;
		sum++;
	}
	vector<char> C;
	int w=max(A.size(),B.size()),v=min(A.size(),B.size());
	if(A.size()>B.size()){
		for(int i=w;i>=v;i--)
		C.push_back(A[i]);
	}
	else if(B.size()>A.size()){
		for(int i=w;i>=v;i--)
		C.push_back(B[i]);
	}
	for(int i=v-1;i>=0;i--){
		if(A[i]!=B[i]) C.push_back('1');
		else C.push_back('0');
	}
	int h=0;
	for(int i=0;i<C.size();i++){
		if(C[i]=='1')
		h=h+pow(2,C.size()-i-1);
	}
	return h;
}
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>a[i];
	int l=1,r=1,s=a[1];
	while(l<=r&&r<=n){
		if(r+1<=n){
			r++;
			s=yi(s,a[r]);
			if(s==k){
				num++;
				l=r+1;
				s=a[l];
				r=l;
			}
		}
		else{
			l++;
			s=yi(s,a[l]);
			if(s==k){
				num++;
			}
		}
	}
	cout<<num;
	return 0;
}

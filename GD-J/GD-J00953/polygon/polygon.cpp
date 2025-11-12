#include<bits/stdc++.h>
using namespace std;

const int N=1e6+5;
int n;
int mid=85959736;
int s[5005];
int aaa(int k,int sum,int m,int a,int b,int c){//k边sum组m长度最大 
	if(k==n) return sum;
	m=max(m,max(s[a],max(s[b],s[c])));
	if(s[a]+s[b]+s[c]>2*m){
		sum++;
	}
	aaa(k++,sum,-1,a+1,b++,c++);
	aaa(k++,sum,-1,a,b++,c++);
	aaa(k++,sum,-1,a,b,c++);
}


int main(){
//	freopen("polygon.in","r",stdin);
//	freopen("polygon.out","w",stdout);
	
	
	cin>>n;
	
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	sort(s+1,s+n+1);
	cout<<aaa(3,0,-1,1,2,3);
	
	return 0;
}


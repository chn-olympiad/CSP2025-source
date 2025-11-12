#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,m,a[N];

bool cmp(int a,int b){
	return a>b;
}

int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}
	int cnt=n*m,num=a[1];
	sort(a+1,a+cnt+1,cmp);
	for(int i=1;i<=cnt;i++){
		if(a[i]==num){
			num=i;
			break;
		}
	}
	
//	cout<<num<<endl;
	int h=num%n,l=num/n+1;
	if(h==0){
		l-=1;
		if(l%2!=0){
			h=n;
		}else{
			h=1;
		}
	}else{
		if(l%2==0){
			h=n-h+1;
		}
	}
	
	cout<<l<<" "<<h;
	
	
	return 0;
}

/*
2 2
99 100 97 98

3 3
94 95 96 97 98 99 100 93 92
*/
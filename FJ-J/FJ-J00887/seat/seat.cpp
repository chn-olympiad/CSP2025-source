#include<bits/stdc++.h>
using namespace std;

int n,m,a,num[110],r;
bool cmp(int s,int d){
	return s>=d;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int x=n*m;
	for(int i=1;i<=x;i++){
		cin>>num[i];
	}
	r=num[1];
	sort(num+1,num+x+1,cmp);
	for(int i=1;i<=x;i++){
		if(num[i]==r){
			a=i;
			break;
		}
	}
	int h,l;
	if(a%n==0){
		l=a/n;
	} else l=a/n+1;
	if(l%2==0){
		if(a%n==0){
			h=1;
		} else{
			h=n-(a%n)+1;
		}
	} else{
		if(a%n==0){
			h=n;
		} else{ 
			h=a%n;
		}
	}
	cout<<l<<" "<<h;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

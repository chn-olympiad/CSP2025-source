#include<bits/stdc++.h>
using namespace std;
int a[1000000];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int n,m,s;
	cin>>n>>m;
	s=n*m;
	for(int i=0;i<s;i++)cin>>a[i];
	int R=a[0],wei=0,l=0,li,hi;
	sort(a,a+s);
	for(int i=0;i<s;i++){
		if(a[i]==R){
			l=i;
			break;
		}
	}
	wei=s-l;
	if(wei%n==0){
		li=(wei-wei%n)/n;
		if(li%2==0)hi=1;
		else hi=n;
	}
	else{
		li=(wei-wei%n)/n+1;
		if(li%2==0)hi=n-wei%n+1;
		else hi=wei%n;
	}
	cout<<li<<" "<<hi;
	fclose(stdin);
	fclose(stdout);
	return 0;
}


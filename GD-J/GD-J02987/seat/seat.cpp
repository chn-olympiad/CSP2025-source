#include<bits/stdc++.h>
using namespace std;
long long n,m,a[105];
bool cmp(long long a,long long b){
	return a>b;
} 
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++)cin>>a[i];
	int rscore=a[1],rseat;
	sort(a+1,a+n*m+1,cmp);
	//for(int i=1;i<=n*m;i++)cout<<a[i]<<" ";
	for(int i=1;i<=n*m;i++){
		if(a[i]==rscore){
			rseat=i;
			break;
		}
	}
	int ansn=rseat/(2*n)*2,ansm=rseat%(2*n);
	if(ansm==0)ansm=1;
	else{
		ansn++;
		if(ansm>n){
			ansn++;
			ansm=n-(ansm-n)+1;
		}
	}
	cout<<ansn<<" "<<ansm;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

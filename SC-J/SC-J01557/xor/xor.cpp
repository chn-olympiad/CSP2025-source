#include<bits/stdc++.h>
using namespace std;
struct z{
	int qd=-1,zd;
}cc[8000000];
int n,k,maxl;
int main(){
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	double a[n];
	cin>>n>>k;
	int h=0;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		int sum=0;
		for(int j=i;j<n;j++){
			if((sum^a[j]==k)){
				cc[h].qd=i;
				cc[h].zd=j;h++;
			}
		}
	}
	int st=cc[0].zd,xx=1;
	for(int i=1;i<h;i++){
		if(cc[i].qd>st){
			xx++;
			st=cc[i].zd;
		}
	}
	st=cc[1].zd;
	int dx=1;
	for(int i=1;i<h;i++){
		if(cc[i].qd>st){
			xx++;
			st=cc[i].zd;
		}
	}
	cout<<max(xx,dx)+1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
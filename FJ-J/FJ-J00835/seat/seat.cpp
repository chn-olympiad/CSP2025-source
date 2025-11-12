#include<bits/stdc++.h>
using namespace std;
int n,m;
int xm,nob,sum,si,it;
int a[250];
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	si=0,it=1,sum=1;
	cin>>n>>m;
	for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
	xm=a[0],nob=0;
	for(int i=1;i<n*m;i++){
		if(a[i]>xm){
			sum++;
		}
	}
	for(int i=1;i<=sum;i++){
		if(it%2==1){
			si++;
			if(si==n+1){
				si--;
				it++;
			}
		}else{
			si--;
			if(si==0){
				si++;
				it++;
			}
		}
	}
	cout<<it<<" "<<si;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

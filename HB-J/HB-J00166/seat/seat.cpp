#include<bits/stdc++.h>
using namespace std;
int a[105];
int t[105];
int main(){
    freopen("seat.in","r",stdin);
    freopen("seat.out","w",stdout);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n*m;i++){
		cin>>a[i];
	}
    int muo=a[0];
	int q=n*m;
	for(int i=0;i<q;i++){
		t[a[i]]++;
	}
	int j=0;
	for(int i=0;i<=100;i++){
		if(t[i]!=0){
			j++;
		}
		if(i==muo){
			break;
		}
	}
	j=q-j;
	j++;
	int u=(j-1)/n+1;
	if(u%2!=0){
		if(j%n==0){
			cout<<u<<" "<<n;
		}else{
			cout<<u<<" "<<j%n;
		}
	}else{
		if(j%n==0){
			cout<<u<<" "<<1;
		}else{
			cout<<u<<" "<<(n-(j%n))+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

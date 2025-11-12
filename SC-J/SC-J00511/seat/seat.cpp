#include<bits/stdc++.h>
using namespace std;
int a[15][15];
int c[110];
int n,m,r,p;
bool cmp(int aa,int bb){
	return aa>bb;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	int k=n*m;
	for(int i=1;i<=k;i++){
		cin>>c[i];
	}
	r=c[1];
	sort(c+1,c+k+1,cmp);
	for(int i=1;i<=k;i++){
		if(c[i]==r){
			p=i;
			break;
		}
	}
	int l=p/n;
	int h=p%n;
	if(h==0){
		cout<<l<<" ";
		if(l%2==0){
			cout<<1;
		}else{
			cout<<n;
		}
	}else{
		cout<<l+1<<" ";
		if((l+1)%2==0){
			cout<<n-h+1;
		}else{
			cout<<h;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0; 
} 
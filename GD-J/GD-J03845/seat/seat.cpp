#include<bits/stdc++.h>
using namespace std;
int a[102],aa,seaat;
bool cmp(int q,int w){
	return q>=w;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.ans","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>a[i];
	}aa=a[1];
	sort(a+1,a+n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
		if(a[i]==aa){
			seaat=i;
			//cout<<seaat;
			break;
		}
	}int mm=seaat/n,nn;
	if(seaat%n!=0){
		mm++;
		if(mm%2==1){
			nn=seaat-n*(mm-1);
		}else{
			nn=n-(seaat-n*(mm-1))+1;
		}
	}if(seaat%n==0){
		if(mm%2==1){
			nn=n;
		}else{
			nn=1;
		}
	}
	cout<<mm<<" "<<nn;
	return 0;
} 

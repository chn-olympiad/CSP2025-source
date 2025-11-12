#include <bits/stdc++.h>
using namespace std;
const int maxn=110;
int n,m;
int a[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	const int nm=n*m;
	for (int i=1;i<=nm;i++){
		cin>>a[i];
	}
	int Rgrade=a[1];
	int Rseat=0;
	sort (a+1,a+nm+1,cmp);
	for (int i=1;i<=nm;i++){
		if (a[i]==Rgrade){
			Rseat=i;
			break;
		}
	}
//	cout<<Rseat<<endl;
	int Rseatx=Rseat;
	while (1){
		if (Rseatx % n !=0){
			Rseatx++;
		}else{
			break;
		}
	}
	int Rx=Rseatx/n;
	int Ry=0;

	if (Rx % 2==1){
		if (Rseat % n==0){
			Ry=n;
		}else{
			Ry=(Rseat%n);
		}
	}else{
		if (Rseat % n==0){
			Ry=1;
		}else{
			Ry=n-(Rseat%n)+1;
		}
	}
	
	cout<<Rx<<" "<<Ry;
	return 0;
}

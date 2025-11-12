#include <bits/stdc++.h>
using namespace std;

int n,m;
int ansn,ansm;
//注意到奇数列从前往后排，偶数列从后往前 
void seat(int a){
	int k=a/n+1;
	if(a%n==0)k-=1;
	if(k%2==1){
		ansn=a-(k-1)*n;
		ansm=k;
	}
	else{
		ansn=k*n-a+1;
		ansm=k;
	}
}

int main(){
	int num;
	int sc[102];
	cin>>n>>m;
	int l=n*m;
	for(int i=0;i<l;i++){
		cin>>sc[i];
	}
	int Rsc=sc[0];
	sort(sc,sc+l);
	for(int i=0;i<l;i++){
		if(Rsc==sc[i]){
			seat(l-i);
		}
	}	
	cout<<ansm<<' '<<ansn<<endl;
	return 0;
}
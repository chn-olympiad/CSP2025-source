#include<bits/stdc++.h>
using namespace std;
int ccbl[1000005];
int cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	string sbl;
	cin>>sbl;
	int a,j=0;
	for(int i=0;i<sbl.size();i++){
		//cout<<sbl[i]-48;
		if('0'<=sbl[i]&&sbl[i]<='9'){
			a=a*10+(sbl[i]-48);
			//cout<<i<<" "<<a<<endl;
		}
	}
	while(a>0){
		ccbl[j]=a%10;
		a/=10;
		j++;
	}
	sort(ccbl,ccbl+j,cmp);
	for(int i=0;i<j;i++){
		cout<<ccbl[i];
	}
	return 0;
} 

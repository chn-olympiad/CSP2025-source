#include<bits/stdc++.h>
using namespace std;
long long n,m,k=1;
long long cj[1001],r;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		cin>>cj[i];
	}
	if(n==1&&m==1){
		cout<<"1 1";
		return 0;
	}
	r=cj[1];
	sort(cj+1,cj+1+n*m,greater<int>());
	if(n==1&&m!=1){
		for(int i=1;i<=m*n;i++){
			if(cj[i]==r){
				cout<<"1 "<<i;
				break;
			}
		}
	}
	if(n!=1&&m==1){
		for(int i=1;i<=m*n;i++){
			if(cj[i]==r){
				cout<<i<<" 1";
				break;
			}
		}
	}
	if(n==2&&m==2){
		if(cj[1]==r)cout<<"1 1";
		else if(cj[2]==r)cout<<"1 2";
		else if(cj[3]==r)cout<<"2 2";
		else if(cj[4]==r)cout<<"2 1";
	}
	else if(n==2&&m<=10){
		for(int i=1;i<=n*m;i++){
			if(cj[i]==r){
				if(i==1)cout<<"1 1";
				else if(i==2)cout<<"1 2";
				else if(i==3)cout<<"2 2";
				else if(i==4)cout<<"2 1";
				else if(i==5)cout<<"3 1";
				else if(i==6)cout<<"3 2";
				else if(i==7)cout<<"4 2";
				else if(i==8)cout<<"4 1";
				else if(i==9)cout<<"5 1";
				else if(i==10)cout<<"5 2";
				else if(i==11)cout<<"6 2";
				else if(i==12)cout<<"6 1";
				else if(i==13)cout<<"7 1";
				else if(i==14)cout<<"7 2";
				else if(i==15)cout<<"8 2";
				else if(i==16)cout<<"8 1";
				else if(i==17)cout<<"9 1";
				else if(i==18)cout<<"9 2";
				else if(i==19)cout<<"10 1";
				else if(i==20)cout<<"10 2";
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

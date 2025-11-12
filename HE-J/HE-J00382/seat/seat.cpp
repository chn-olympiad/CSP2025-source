#include<bits/stdc++.h>
#define N 13
#define NN 124
using namespace std;
int a[N][N];
int numn[NN];
bool cmod (int a,int b){
	return !(a%b);
}
int main(){
	
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);

	int n,m,ini=0,inj=0,my_n,num_seat,my_m;
	cin>>n>>m;
	if(n==1 && m==1){
		cout<<1<<" "<<1;
		return 0;
	}
	int nm=n*m;
	cin>>numn[0];
	int my_point=numn[0];
	for(int i=1;i<nm;i++)
		cin>>numn[i];
	
	sort(numn,numn+nm);
	for(int i=0;i<nm;i++)
		cout<<numn[i]<<" ";
	cout<<endl;
	for(int i=0;i<nm;i++){
		if(numn[i]==my_point){
			num_seat=nm-i;
			break;
		}
	}
	cout<<num_seat<<endl;
	if(num_seat/n*n!=num_seat) my_m=num_seat/n+1;
	else{
		if((num_seat)%n==1) my_m=num_seat/n+1;
		else my_m=(num_seat)/n;
	} 
	
	if(cmod(my_m,2) && num_seat/n*n!=num_seat) my_n=n-(num_seat%n)+1;
	else if(cmod(my_m,2) && num_seat/n*n==num_seat) my_n=n-((num_seat)%n)+2;
	else if(!cmod(my_m,2) && num_seat/n*n!=num_seat) my_n=num_seat%n+1;
	else my_n=(num_seat)%n+2;
	cout<<my_m<<" "<<my_n;

	fclose(stdin);
	fclose(stdout);
	
	return 0;
}

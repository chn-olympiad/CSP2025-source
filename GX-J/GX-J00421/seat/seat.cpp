#include<bits/stdc++.h>
using namespace std;
int n,m,sor,rank_,ans_h,ans_l;
int a[105];
void input(){
	cin>>n>>m;cin>>sor;
    a[0]=sor;
    for(int i=1;i<n*m;i++){
		cin>>a[i];
	}
}
/*void line(){
	cout<<endl;
	for(int i=0;i<=20;i++){
		cout<<"=";
	}cout<<endl;
}*/
void swpa(int &a,int &b){
	int tem;
	tem=a;
	a=b;
	b=tem;
}
void selfsort(){
	bool s=1;
	while (s){
		s=0;
		for(int i=0;i<n*m;i++){
		    if(a[i]<a[i+1]){
				s=1;
				swpa(a[i],a[i+1]);
			}
	    }
	}
}
void find_(){
	for(int i=0 ;i<n*m;i++)
		if(a[i]==sor){
			rank_=i;
		}
	}
void sovle(){
	ans_l=ceil(rank_/n);
	if(ans_l%2==0){
		ans_h=rank_%n+1;
	}else{
		for(int i=n;i>=1;i--){
			if(i+(rank_%n)==n){
				ans_h=i;
			}
		}
	}
}
int main (){
    freopen ("seat.in","r",stdin);
    freopen ("seat.out","w",stdout);
    input();
	selfsort();
	find_();
	sovle();
	/*for(int i=0;i<n*m;i++){
		cout<<a[i]<<" ";
	}
	line();
	cout<<rank_;
	line();*/
	cout<<ans_l+1<<" "<<ans_h<<endl;
    return 0;
}

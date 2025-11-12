#include<bits/stdc++.h>
using namespace std;
int student[105];
int cmp(int a,int b){
	return a>b;
}
int main(){
	//freopen("seat.in","r",stdin);
	//freopen("seat.out","w",stdout);
	int n,m,R,seat,c,r;
	cin>>n>>m;
	for(int i=1;i<n*m;i++){
	
	student[i];
	cin>>student[i];
	R=student[1];
	sort(student +1,student +n*m+1,cmp);
	for(int i=1;i<=n*m;i++){
	
	if(student [i]==R){
	seat=i;
	break;
	
		}
	}

}
if((seat/m)==0){
	r=0;
}else{
	r=seat%m;
}
if((seat/m)%2==0){
	r=1;
}
else{
	r=seat%m;
}
cout<<c<<" "<<r<<endl;	
return 0;

}

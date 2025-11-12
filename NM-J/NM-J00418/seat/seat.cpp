#include<bits/stdc++.h>
using namespace std;
int a,b,c,d,e=1;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b>>c;
	for(int i=1;i<=a*b-1;i++){
		cin>>d;
		if(d>c){
			e++;
		}
	}
	if(e%a==0){
		if((e/a)%2==0){
			cout<<e/a<<" "<<a;
		}
		else{
			cout<<e/a<<" "<<1;
		}
	}
	else{
		if((e/a+1)%2==0){
			cout<<e/a+1<<" "<<a-e%a+1;
		}
		else{
			cout<<e/a+1<<" "<<e%a;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

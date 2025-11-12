#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int a,c;
	cin>>a>>c;
	int fs[a*c],b,j=0,x,y,z;
	cin>>b;
	fs[0]=b;
	for(int i=1;i<a*c;i++){
		cin>>fs[i];
	}
	sort(fs,fs+a*c);
	while(fs[j]!=b){
		j++;
	}
	z=a*c-j;
	if(z%a==0)y=z/a;
	else y=z/a+1;
	if(y%2==0)x=a-z%a;
	else x=z%a+1;
	cout<<y<<" "<<x;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

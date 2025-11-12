#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen('seat.in','r',stdin);
	freopen('seat.out','w',stdout);
	int a,b,c[101],d,e = 0;
	cin>>a>>b;
	for(int i = 0;i<a;i++){
		for(int j = 0;j<b;j++){
			cin>>c[e];
			e++;
		}
	}
	d = c[0];
	sort(c,c+a*b);
	for(int i=0;i<a;i++){
		if(c[i] == d){
			cout<<i%a+1<<' '<<i/a+1;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}

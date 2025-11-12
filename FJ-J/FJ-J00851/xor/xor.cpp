#include<bits\stdc++.h>
using namespace std;
int main(){
	freopen('xor.in','r',stdin);
	freopen('xor.out','w',stdout);
	int a,b,c[500001],head,t,d = 0,f = 0;
	cin>>a>>b;
	for(int i=0;i<a;i++){
		cin>>c[i];
	}
	for(int i=0;i<a;i++){
		if(t-head+1 == a){
			break;
		}
		head = i;
		d = 0;
		t = head;
		for(int j=head;t<a;t++){
			d = d^c[t];
			if (d==b){
				f++;
				break;
			}
		}
	}
	cout<<f;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

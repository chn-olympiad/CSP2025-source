#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int b,c,k[1005],l,o=1,p=1,e=0,h;
	cin>>b>>c;
	for(int i=1;i<=b*c;i++){
			cin>>k[i];
			l=k[1];
	}
	for(int i=1;i<=b*c;i++){
		for(int j=1;j<=b*c;j++){
			if(k[j]<k[j+1]){
				h=k[j];
				k[j]=k[j+1];
				k[j+1]=h;
			}
		}
	}
	if(b*c==1)cout<<"1"<<" "<<"1";
	for(int i=2;i<=b*c+1;i++){
		e++;
		if(e/b>0&&k[i]!=l){
			p++;
			e=0;
		}
		if(k[i]==l){
			if(p%2==0){
				if(e==0){
					e=b;
				}
				e=b-e+1;
				cout<<p<<" "<<e;
				return 0;
			}else{
				if(e==0){
					e=1;
				}
				cout<<p<<" "<<e;
				return 0;
			}
		}
	}
	return 0;
}

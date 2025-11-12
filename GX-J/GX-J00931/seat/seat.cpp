#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","w",stdin);
	freopen("seat.out","r",stdout);
	int a,b;
	cin>>a>>b;
	int c[a*b+1];
	for(int i=0;i<a*b;i++)cin>>c[i];
		int e=c[0],g=0;
		for(int i=0;i<a*b;i++){
				if(c[i]<c[i+1]){
					int d=c[i];
					c[i]=c[i+1];
					c[i+1]=d;
					}
				}
			for(int i=1;i<=10;i++){
					if(i%2!=0){
						for(int j=1;j<b;j++){
							g++;
							if(c[g]==e){
								if(i==1){
									cout<<i<<' '<<j+1;
									return 0;
								}
								cout<<i<<' '<<j;
								return 0;
								}
							}
					}
					else{
						for(int j=b;j>0;j--){
							g++;
							if(c[g]==e){
								cout<<i<<' '<<j;
								return 0;
						}
						}
				}
				}
	return 0;
}

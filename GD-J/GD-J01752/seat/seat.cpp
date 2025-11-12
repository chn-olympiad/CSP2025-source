#include<bits/stdc++.h>
using namespace std;
long long a,b,f,g,i=0;
struct aa{
	long long a,b=0;
}c[1005];
bool cmp(aa d,aa e){
	return d.a>e.a;
}
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	cin>>a>>b;
	f=a*b;
	cin>>c[1].a;
	c[1].b=1;
	for(int z=2;z<=f;z++)cin>>c[z].a;
	sort(c+1,c+1+f,cmp);
	for(int z=1;z<=f;z++){
		if(c[z].b==1){
			g=z;
			break;
		}
	}
	for(int z=1;z<=a;z++){
		if(z%2==1){
			for(int y=1;y<=b;y++){
				i++;
				if(i==g){
					cout<<z<<' '<<y;
					return 0;
				}
			}	
		}
		else{
			for(int y=b;y>=1;y--){
				i++;
				if(i==g){
					cout<<z<<" "<<y;
					return 0;
				}
			}
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

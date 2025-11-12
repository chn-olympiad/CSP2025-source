#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("seat.in","r",stdin);
	freopen("seat.out","w",stdout);
	int c,t,point[205];
	cin>>c>>t;
	int number=c*t;
	int x;
	for(int i=0;i<number;i++){
		cin>>x;
		point[i]=-x;
	} 
	int num=point[0];
	sort(point,point+number);
	int site;
	for(int i=0;i<number;i++){
		if(point[i]==num){
			site=i+1;
			break;
		}
	}
	if(site%c==0){
		if((site/c)%2==0){
			cout<<site/c<<' '<<1;
		}
		else{
			cout<<site/c<<' '<<c;
		}
	}
	else{
		int site_t=site/c+1;
		int c_number=site-site/c*c;
		if(site_t%2==0){
			cout<<site_t<<' '<<c-c_number+1;
		}
		else{
			cout<<site_t<<' '<<c_number;
		} 
	}





	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 

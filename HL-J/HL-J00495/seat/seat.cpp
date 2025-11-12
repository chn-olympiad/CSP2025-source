#include<iostream>	
int main(){	
	int n,m,a[11][11],s[101];
	int t=-1,q,x=1,y=1;
	std::cin>>n>>m;
	for(int i=1;i<=n*m;i++){
		std::cin>>s[i];
		if(s[i]>t) {
			t=s[i];
			q=i;
		}
	}
	if(q==1){
		std::cout<<1<<" "<<1;
		return 0;	
	}
	y++;
	for(int l=1;l<=n*m;l++){
		s[q]=-1;
		t=-1;
		for(int i=1;i<=n*m;i++){
			if(s[i]>t){
				t=s[i];
				q=i;
			}
		}
		if(q==1){
				std::cout<<x<<" "<<y;
				return 0;
		}
		else {
			if(y==1 && x%2==0){
				x++;
			}
			else if(y==n && x%2==1) x++;
			else if(x%2==1) y++;
			else if(x%2==0) y--;
		}
	}
	
	
	return 0;
}